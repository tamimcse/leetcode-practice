/*
https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/

https://www.geeksforgeeks.org/iterative-depth-first-traversal/
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

void dfs_rec_inner (struct graph *g, int v, int *visited)
{
  visited[v] = 1;
  printf ("%d ", v);
  struct edge *runner = g->adj_list[v];
  while (runner) {
    if (!visited[runner->v])
      dfs_rec_inner (g, runner->v, visited);
    runner = runner->next;
  }
}

void dfs_rec (struct graph *g)
{
  int *visited = (int *) calloc (g->vertices_num, sizeof (*visited));
  dfs_rec_inner (g, 0, visited);
}

void dfs_itr (struct graph *g)
{
  int *visited = (int *) calloc (g->vertices_num, sizeof (*visited));
  int *stack = (int *) calloc (g->edges_num, sizeof (*stack));
  int s_idx = 0, cur_node;
  struct edge *runner;

  stack[s_idx++] = 0;
  while (s_idx) {
    cur_node = stack[--s_idx];
    printf ("%d ", cur_node);
    visited[cur_node] = 1;
    runner = g->adj_list[cur_node];
    while (runner) {
      if (!visited[runner->v])
        stack[s_idx++] = runner->v;
      runner = runner->next;
    }
  }
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

  dfs_rec (&g);
  printf ("\n");

  dfs_itr (&g);
  printf ("\n");
}
