/*
https://www.geeksforgeeks.org/topological-sorting/
*/
#include <stdio.h>
#include <stdlib.h>

struct edge {
  int v;
  struct edge *next;
};

struct graph {
  struct edge **adj_list;
  int vertices_num;
  int edges_num;
};

void insert_edge (struct graph *g, int v1, int v2)
{
  struct edge *new_edge = (struct edge *) malloc (sizeof (*new_edge));
  new_edge->v = v2;
  new_edge->next = g->adj_list[v1];
  g->adj_list[v1] = new_edge;
  g->edges_num++;
}

void dfs_rec (struct graph *g, int v, int *visited, int *stack, int *s_idx)
{
  visited[v] = 1;
  struct edge *runner = g->adj_list[v];
  while (runner) {
    if (!visited[runner->v])
      dfs_rec (g, runner->v, visited, stack, s_idx);
    runner = runner->next;
  }
  stack[(*s_idx)++] = v;
}

void topologocal_sorting (struct graph *g)
{
  int *visited = (int *) calloc (g->vertices_num, sizeof (*visited));
  int *stack = (int *) calloc (g->vertices_num, sizeof (*stack));
  int s_idx = 0;
  dfs_rec (g, 0, visited, stack, &s_idx);

  for (int i = s_idx - 1; i >= 0; i--) {
    printf ("%d ", stack[i]);
  }
  printf ("\n");
}

void main ()
{
  struct graph g;
  g.vertices_num = 7;
  g.edges_num = 0;
  g.adj_list = (struct edge **) calloc (g.vertices_num, sizeof (*(g.adj_list)));
  insert_edge (&g, 0, 1);
  insert_edge (&g, 1, 2);
  insert_edge (&g, 2, 3);
  insert_edge (&g, 0, 6);
  insert_edge (&g, 6, 5);
  insert_edge (&g, 6, 4);
  insert_edge (&g, 2, 4);
  insert_edge (&g, 4, 3);
  insert_edge (&g, 5, 3);

  topologocal_sorting (&g);
}
