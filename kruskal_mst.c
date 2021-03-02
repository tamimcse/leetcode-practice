/*
Minimum spanning tree (MST) using kruskal's algoritgm
*/
#include <stdio.h>
#include <stdlib.h>

struct edge {
  int v1;
  int v2;
  int weight;
};

int edge_cmp (const void *e1, const void *e2)
{
  return ((struct edge *)e1)->weight - ((struct edge *)e2)->weight; 
}

struct graph {
  int num_vertices;
  int num_edges;
  struct edge *edges;
};


int main ()
{
  int i;
  //Init the graph at https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/
  struct graph *g = (struct graph *) malloc (sizeof (*g));
  g->num_vertices = 9;
  g->num_edges = 14;
  g->edges = (struct edge *) malloc (g->num_edges * sizeof (*(g->edges)));
  //edge 0
  g->edges[0].v1 = 0; g->edges[0].v2 = 1; g->edges[0].weight = 4;
  //edge 1
  g->edges[1].v1 = 1; g->edges[1].v2 = 2; g->edges[1].weight = 8;
  //edge 2
  g->edges[2].v1 = 2; g->edges[2].v2 = 3; g->edges[2].weight = 7;
  //edge 3
  g->edges[3].v1 = 3; g->edges[3].v2 = 4; g->edges[3].weight = 9;
  //edge 4
  g->edges[4].v1 = 4; g->edges[4].v2 = 5; g->edges[4].weight = 10;
  //edge 5
  g->edges[5].v1 = 5; g->edges[5].v2 = 6; g->edges[5].weight = 2;
  //edge 6
  g->edges[6].v1 = 6; g->edges[6].v2 = 7; g->edges[6].weight = 1;
  //edge 7
  g->edges[7].v1 = 7; g->edges[7].v2 = 0; g->edges[7].weight = 8;
  //edge 8
  g->edges[8].v1 = 7; g->edges[8].v2 = 1; g->edges[8].weight = 11;
  //edge 9
  g->edges[9].v1 = 7; g->edges[9].v2 = 8; g->edges[9].weight = 7;
  //edge 10
  g->edges[10].v1 = 6; g->edges[10].v2 = 8; g->edges[10].weight = 6;
  //edge 11
  g->edges[11].v1 = 2; g->edges[11].v2 = 8; g->edges[11].weight = 2;
  //edge 12
  g->edges[12].v1 = 2; g->edges[12].v2 = 5; g->edges[12].weight = 4;
  //edge 13
  g->edges[13].v1 = 3; g->edges[13].v2 = 5; g->edges[13].weight = 14;

  //sort the edges
  qsort (g->edges, g->num_edges, sizeof (struct edge), edge_cmp);

  //print the edges
  for (i = 0; i < g->num_edges; i++) {
    printf ("%d ", g->edges[i].weight);
  }
  printf ("\n");

}
