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

struct node* clone (struct node *r)
{

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
}
