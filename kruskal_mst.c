/*
Minimum spanning tree (MST) using kruskal's algoritgm
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct edge {
  int v1;
  int v2;
  int weight;
};


struct graph {
  int num_vertices;
  int num_edges;
  struct edge **adjacency_matrix;
  struct edge *edges;
};

struct graph *create_graph (int v, int e)
{
  struct graph *g = (struct graph *) malloc (sizeof (*g));
  g->num_vertices = v;
  g->num_edges = e;
  g->edges = (struct edge *) calloc (g->num_edges, sizeof (*g->edges));
  g->adjacency_matrix = (struct edge **) calloc (g->num_vertices * g->num_vertices, sizeof (*g->adjacency_matrix));
  return g;
}

int insert_edge (struct graph *g, int idx, int i, int j, int weight)
{
  struct edge *runner;

  if (i >= g->num_vertices || j >= g->num_vertices || idx >= g->num_edges)
    return 1;

  g->edges[idx].v1 = i;
  g->edges[idx].v2 = j;
  g->edges[idx].weight = weight;

  g->adjacency_matrix[i * g->num_vertices + j] = &g->edges[idx];
  g->adjacency_matrix[j * g->num_vertices + i] = &g->edges[idx];

  return 0;
} 

void print_graph (struct graph *g)
{
  int i, j;

  printf ("Number of vertices %d\n", g->num_vertices);
  printf ("Edges: \n");
  for (i = 0; i < g->num_vertices; i++) {
    for (j = 0; j < g->num_vertices; j++) {
      struct edge *e = g->adjacency_matrix[i * g->num_vertices + j];
      if (e) {
        printf ("%d,%d. %d->%d:%d\n", i, j, e->v1, e->v2, e->weight);
      }
    }
  }
}

int edge_cmp (const void *e1, const void *e2) {
   return ((struct edge *)e1)->weight - ((struct edge *)e2)->weight;
}
 
void kruskal_mst (struct graph *g)
{
  int i;

  struct edge *edge_arr = (struct edge *) malloc (g->num_edges * sizeof (*edge_arr));
  memcpy (edge_arr, g->edges, g->num_edges * sizeof (*edge_arr));
  qsort (edge_arr, g->num_edges, sizeof (*edge_arr), edge_cmp);
  printf ("Edges after sorting....\n");
  for (i = 0; i < g->num_edges; i++) {
    printf ("%d->%d:%d\n", edge_arr[i].v1, edge_arr[i].v2, edge_arr[i].weight);
  }
}

int main ()
{
  int i;
  //Init the graph at https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/
  struct graph *g = create_graph (9, 14);
  insert_edge (g, 0, 0, 1, 4);
  insert_edge (g, 1, 1, 2, 8);
  insert_edge (g, 2, 2, 3, 7);
  insert_edge (g, 3, 3, 4, 9);
  insert_edge (g, 4, 4, 5, 10);
  insert_edge (g, 5, 5, 6, 2);
  insert_edge (g, 6, 6, 7, 1);
  insert_edge (g, 7, 7, 0, 8);
  insert_edge (g, 8, 7, 1, 11);
  insert_edge (g, 9, 7, 8, 7);
  insert_edge (g, 10, 8, 2, 2);
  insert_edge (g, 11, 8, 6, 6);
  insert_edge (g, 12, 2, 5, 4);
  insert_edge (g, 13, 3, 5, 14);
  print_graph (g);
  kruskal_mst (g);
}
