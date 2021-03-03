/*
Minimum spanning tree (MST) using kruskal's algoritgm
*/
#include <stdio.h>
#include <stdlib.h>

struct edge {
  int v1;
  int v2;
  int weight;
  struct edge *next;
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

struct graph *create_graph (int v, int e)
{
  struct graph *g = (struct graph *) malloc (sizeof (*g));
  g->num_vertices = v;
  g->num_edges = e;
  g->edges = (struct edge *) malloc (g->num_edges * sizeof (*(g->edges)));
  return g;
}

void print_edges (struct graph *g)
{
  int i;

  for (i = 0; i < g->num_edges; i++) {
    printf ("%d ", g->edges[i].weight);
  }
  printf ("\n");
}

int check_cycle (struct edge* head, struct edge* new_edge)
{

}

struct edge* kruskal_mst (struct graph *g)
{
  struct edge* head = NULL;
  int i;
  int num_vertices_mst = 0;//Number of vertices in MST
  //sort the edges
  qsort (g->edges, g->num_edges, sizeof (struct edge), edge_cmp);
  //print_edges (g);
  
  for (i = 0; i < g->num_edges; i++) {
    
  }

  return head;
}

int main ()
{
  int i;
  //Init the graph at https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/
  struct graph *g = create_graph (9, 14);
  //edge 0
  g->edges[0].v1 = 0; g->edges[0].v2 = 1; g->edges[0].weight = 4; g->edges[0].next = NULL;
  //edge 1
  g->edges[1].v1 = 1; g->edges[1].v2 = 2; g->edges[1].weight = 8; g->edges[1].next = NULL;
  //edge 2
  g->edges[2].v1 = 2; g->edges[2].v2 = 3; g->edges[2].weight = 7; g->edges[2].next = NULL;
  //edge 3
  g->edges[3].v1 = 3; g->edges[3].v2 = 4; g->edges[3].weight = 9; g->edges[3].next = NULL;
  //edge 4
  g->edges[4].v1 = 4; g->edges[4].v2 = 5; g->edges[4].weight = 10; g->edges[4].next = NULL;
  //edge 5
  g->edges[5].v1 = 5; g->edges[5].v2 = 6; g->edges[5].weight = 2; g->edges[5].next = NULL;
  //edge 6
  g->edges[6].v1 = 6; g->edges[6].v2 = 7; g->edges[6].weight = 1; g->edges[6].next = NULL;
  //edge 7
  g->edges[7].v1 = 7; g->edges[7].v2 = 0; g->edges[7].weight = 8; g->edges[7].next = NULL;
  //edge 8
  g->edges[8].v1 = 7; g->edges[8].v2 = 1; g->edges[8].weight = 11; g->edges[8].next = NULL;
  //edge 9
  g->edges[9].v1 = 7; g->edges[9].v2 = 8; g->edges[9].weight = 7; g->edges[9].next = NULL;
  //edge 10
  g->edges[10].v1 = 6; g->edges[10].v2 = 8; g->edges[10].weight = 6; g->edges[10].next = NULL;
  //edge 11
  g->edges[11].v1 = 2; g->edges[11].v2 = 8; g->edges[11].weight = 2; g->edges[11].next = NULL;
  //edge 12
  g->edges[12].v1 = 2; g->edges[12].v2 = 5; g->edges[12].weight = 4; g->edges[12].next = NULL;
  //edge 13
  g->edges[13].v1 = 3; g->edges[13].v2 = 5; g->edges[13].weight = 14; g->edges[13].next = NULL;

  struct edge *head = kruskal_mst (g);
  //print the list
  while (head) {
    printf ("%d -> %d : %d\n", head->v1, head->v2, head->weight);
    head = head->next;
  }

}
