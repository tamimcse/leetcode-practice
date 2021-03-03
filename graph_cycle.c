/*
Detect a cycle in a graph
*/
#include <stdio.h>
#include <stdlib.h>

struct edge {
  int v1;
  int v2;
  struct edge *next;
};


struct graph {
  int num_vertices;
  struct edge **adjacency_list;
};

struct graph *create_graph (int v)
{
  struct graph *g = (struct graph *) malloc (sizeof (*g));
  g->num_vertices = v;
  g->adjacency_list = (struct edge **) calloc (g->num_vertices, sizeof (*g->adjacency_list));
  return g;
}

int insert_edge (struct graph *g, int i, int j)
{
  struct edge *runner;

  if (i >= g->num_vertices || j >= g->num_vertices)
    return 1;

  struct edge *new_edge = (struct edge *) malloc (sizeof (*new_edge));
  new_edge->v1 = i;
  new_edge->v2 = j;
  new_edge->next = g->adjacency_list[i];
  g->adjacency_list[i] = new_edge;
  return 0;
} 

void print_graph (struct graph *g)
{
  int i;
  struct edge *runner = NULL;

  printf ("Number of vertices %d\n", g->num_vertices);
  printf ("Edges: \n");
  for (i = 0; i < g->num_vertices; i++) {
    runner = g->adjacency_list[i];
    while (runner) {
      printf ("%d->%d ", runner->v1, runner->v2);
      runner = runner->next;
    }
    printf ("\n");
  }
}
/*
int check_cycle (struct edge* head, struct edge* new_edge)
{

}
*/

int main ()
{
  int i;
  //Init the graph at https://www.geeksforgeeks.org/detect-cycle-in-a-graph/
  struct graph *g = create_graph (4);
  insert_edge (g, 0, 1);
  insert_edge (g, 1, 2);
  insert_edge (g, 2, 0);
  insert_edge (g, 0, 2);
  insert_edge (g, 2, 3);
  insert_edge (g, 3, 3);
  print_graph (g);
}
