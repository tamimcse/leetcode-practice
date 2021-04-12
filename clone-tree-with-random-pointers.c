/*
https://www.geeksforgeeks.org/clone-binary-tree-random-pointers/

https://practice.geeksforgeeks.org/problems/clone-a-binary-tree/1/?company[]=Synopsys&company[]=Synopsys&page=1&query=company[]Synopsyspage1company[]Synopsys
*/
#include <stdio.h>
#include <stdlib.h>

struct node {  
  int data; 
  struct node *left;
  struct node *right;
  struct node *random;
};

struct node_map {
  struct node *key;
  struct node *value;
};

struct node* clone_inner (struct node *r, struct node_map *map, int *map_count)
{
  struct node *left = NULL, *right = NULL, *new_node;
  if (r->left)
    left = clone_inner (r->left, map, map_count);
  if (r->right)
    right = clone_inner (r->right, map, map_count);
  new_node = (struct node*) malloc (sizeof (*new_node));
  new_node->data = r->data;
  new_node->left = left;
  new_node->right = right;
  map[*map_count].key = r;
  map[*map_count].value = new_node;
  (*map_count)++;
  return new_node;
}

struct node* find_value (struct node_map *map, int map_count, struct node *key)
{
  int i;

  for (i = 0; i < map_count; i++) {
    if (map[i].key == key)
      return map[i].value;
  }
  return NULL;
}

void set_random_pointer (struct node *r, struct node_map *map, int map_count)
{
  if (r->random)
    find_value(map, map_count, r)->random = find_value(map, map_count, r->random);
  if (r->left)
    set_random_pointer (r->left, map, map_count);
  if (r->right)
    set_random_pointer (r->right, map, map_count);
}

struct node* clone (struct node *r)
{
  struct node_map map[10] = {0};
  int map_count = 0;

  struct node *res = clone_inner (r, map, &map_count);
  set_random_pointer (r, map, map_count);
  return res;
}

void print (struct node *r)
{
  if (!r)
    return;

  printf ("%d", r->data);
  if (r->random) {
    printf ("->%d", r->random->data);
  }
  printf(" ");
  print (r->left);
  print (r->right);
}

void main ()
{
  struct node n1, n2, n3, n4, n5, n6, n7;
  n1 = (struct node) {1, &n2, &n3, NULL};
  n2 = (struct node) {2, &n4, &n5, NULL};
  n3 = (struct node) {3, NULL, NULL, NULL};
  n4 = (struct node) {4, NULL, NULL, NULL};
  n5 = (struct node) {5, &n6, &n7, &n1};
  n6 = (struct node) {6, NULL, NULL, &n2};
  n7 = (struct node) {7, NULL, NULL, &n3};
  printf ("Original tree = ");
  print (&n1);
  printf ("\n");

  struct node *res = clone (&n1);

  printf ("Cloned tree = ");
  print (res);
  printf ("\n");
}
