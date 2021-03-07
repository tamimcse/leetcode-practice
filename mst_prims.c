/*
Minimum spanning tree (MST) - Prim's algorithm.

https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/
*/
#include <stdio.h>
#include <stdlib.h>

struct graph {
  int num_vertices;
  int num_edges;
  int *adjacency_matrix;
};

struct graph* create_graph (int v)
{
  struct graph *g = (struct graph *) malloc (sizeof (*g));
  g->num_vertices = v;
  g->num_edges = 0;
  g->adjacency_matrix = (int *) calloc (v * v, sizeof (g->adjacency_matrix));
  return g;
}

int insert_edge (struct graph *g, int v1, int v2, int weight)
{
  if (v1 >= g->num_vertices || v2 >= g->num_vertices) {
    return 1;
  }

  g->adjacency_matrix[v1 * g->num_vertices + v2] = weight;
  g->adjacency_matrix[v2 * g->num_vertices + v1] = weight;
  g->num_edges++;
  return 0;
}

void graph_print (struct graph *g)
{
  int i, j;

  printf ("Edges:\n");
  for (i = 0; i < g->num_vertices; i++) {
    for (j = 0; j < g->num_vertices; j++) {
      if (g->adjacency_matrix[i * g->num_vertices + j])
        printf ("%d->%d %d\n", i, j, g->adjacency_matrix[i * g->num_vertices + j]);
    }
  }
}

void main ()
{
  //Init the graph at https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/
  struct graph *g = create_graph (9);
  insert_edge (g, 0, 1, 4);
  insert_edge (g, 1, 2, 8);
  insert_edge (g, 2, 3, 7);
  insert_edge (g, 3, 4, 9);
  insert_edge (g, 4, 5, 10);
  insert_edge (g, 5, 6, 2);
  insert_edge (g, 6, 7, 1);
  insert_edge (g, 7, 0, 8);
  insert_edge (g, 7, 1, 11);
  insert_edge (g, 7, 8, 7);
  insert_edge (g, 8, 2, 2);
  insert_edge (g, 8, 6, 6);
  insert_edge (g, 2, 5, 4);
  insert_edge (g, 3, 5, 14);
  graph_print (g);
}
