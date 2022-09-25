/*
https://www.geeksforgeeks.org/find-longest-path-directed-acyclic-graph/
*/
#include <stdio.h>
#include <stdlib.h>

struct edge {
  int v;
  int weight;
  struct edge *next;
};

struct graph {
  struct edge **adj_list;
  int vertices_num;
  int edges_num;
};

void insert_edge (struct graph *g, int v1, int v2, int weight)
{
  struct edge *new_edge = (struct edge *) malloc (sizeof (*new_edge));
  new_edge->v = v2;
  new_edge->weight = weight;
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

int* topologocal_sorting (struct graph *g)
{
  int *visited = (int *) calloc (g->vertices_num, sizeof (*visited));
  int *stack = (int *) calloc (g->vertices_num, sizeof (*stack));
  int *res = (int *) calloc (g->vertices_num, sizeof (*res));
  int s_idx = 0;
  dfs_rec (g, 0, visited, stack, &s_idx);
  for (int i = s_idx - 1, j = 0; i >= 0; i--, j++) {
    res[j] = stack[i];
  }
  return res;
}

#define NINF -100

int longest_path (struct graph *g)
{
  int i, curr_vertex, adj_vertex;
  struct edge *runner;
  int *topological_order = topologocal_sorting (g);
  int *longest_path = (int *) calloc (g->vertices_num, sizeof (*longest_path));

  longest_path[topological_order[0]] = 0;
  for (i = 1; i < g->vertices_num; i++) {
    longest_path[topological_order[i]] = NINF;
  }

  for (i = 0; i < g->vertices_num - 1; i++) {
    curr_vertex = topological_order[i];
    runner = g->adj_list[curr_vertex];
    while (runner) {
      adj_vertex = runner->v;
      if (longest_path[adj_vertex] < longest_path[curr_vertex] + runner->weight)
        longest_path[adj_vertex] = longest_path[curr_vertex] + runner->weight;
      runner = runner->next;
    }
  }

  int max_path = longest_path[0];
  for (i = 1; i < g->vertices_num; i++) {
    if (max_path < longest_path[i])
      max_path = longest_path[i];
  }
  return max_path;
}

void main ()
{
  struct graph g;
  g.vertices_num = 7;
  g.edges_num = 0;
  g.adj_list = (struct edge **) calloc (g.vertices_num, sizeof (*(g.adj_list)));
  insert_edge (&g, 0, 1, 2);
  insert_edge (&g, 1, 2, 3);
  insert_edge (&g, 2, 3, 2);
  insert_edge (&g, 0, 6, 1);
  insert_edge (&g, 6, 5, 2);
  insert_edge (&g, 6, 4, 3);
  insert_edge (&g, 2, 4, 2);
  insert_edge (&g, 4, 3, 2);
  insert_edge (&g, 5, 3, 1);

  int res = longest_path (&g);
  printf ("Longest path = %d \n", res);
}
