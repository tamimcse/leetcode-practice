/*
https://www.geeksforgeeks.org/given-array-strings-find-strings-can-chained-form-circle/

https://www.geeksforgeeks.org/hamiltonian-cycle-backtracking-6/
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct edge {
  int v;
  struct edge *next;
};

struct graph {
  struct edge **adj_list;
  int vertices_num;
  int edges_num;
};

struct graph* create_graph (char **arr, int len)
{
  int i, j;
  struct graph *g = (struct graph *) malloc (sizeof (*g));
  g->vertices_num = len;
  g->adj_list = (struct edge**) calloc (g->vertices_num, sizeof (*(g->adj_list)));

  for (i = 0; i < len; i++) {
    for (j = 0; j < len; j++) {
      if (i == j)
        continue;
      if (arr[i][strlen(arr[i]) - 1] == arr[j][0]) {
        printf ("Inserting edge between %d and %d \n", i, j);
        struct edge *new_edge = (struct edge *) malloc (sizeof (*new_edge));
        new_edge->v = j;
        new_edge->next = g->adj_list[i];
        g->adj_list[i] = new_edge;
        g->edges_num++;
      } 
    }
  }
  return g;
}

void print_graph (struct graph *g)
{
  int i;
  struct edge *runner;

  for (i = 0; i < g->vertices_num; i++) {
    printf ("%d : ", i);
    runner = g->adj_list[i];
    while (runner) {
      printf ("%d ", runner->v);
      runner = runner->next;
    }
    printf ("\n");
  }
}

bool is_hamiltonian_cycle_backtracking (struct graph *g, int start, int *visit, int *chain_length)
{
  bool res = false;
  if (start == 0 && *chain_length == g->vertices_num)
    return true;

  if (visit[start])
    return false;
  visit[start] = 1;
  struct edge *runner = g->adj_list[start];

  while (runner) {
    (*chain_length)++;
    res = is_hamiltonian_cycle_backtracking (g, runner->v, visit, chain_length);
    if (res)
      return res;
    (*chain_length)--;
    runner = runner->next;
  }
  visit[start] = 0;
  return false;  
}

bool is_hamiltonian_cycle (struct graph *g)
{
  int *visit = (int *) calloc (g->vertices_num, sizeof (*visit));
  int chain_length = 0;

  return is_hamiltonian_cycle_backtracking (g, 0, visit, &chain_length);
}

bool can_str_form_circle (char **arr, int len)
{
  struct graph *g = create_graph (arr, len);
  print_graph (g);
  return is_hamiltonian_cycle (g);
}

void main ()
{
  char *arr[] = {"for", "geek", "rig", "kaf"};
  int arr_len = sizeof (arr) / sizeof (arr[0]);
  
  bool res = can_str_form_circle (arr, arr_len);
  if (res)
   printf ("Yes, they can form a circle\n");
  else
   printf ("No, they can't form a circle\n");
}
