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

int check_cycle_inner (struct graph *g, int i, int *nodes_visited)
{
  int res;

  struct edge *runner = g->adjacency_list[i];
  //the graph has a cycle
  if (nodes_visited[i])
    return 1;
  //mark the source node visited
  nodes_visited[i] = 1;
  while (runner) {
    res = check_cycle_inner (g, runner->v2, nodes_visited);
    //cycle found
    if (res)
      return 1;
    runner = runner->next;
  }
  //unmark the source
  nodes_visited[i] = 0;
  return 0;
}

int check_cycle (struct graph *g)
{
  int res;

  //This array keeps track of the nodes that are visited
  int *nodes_visited = (int *) calloc (g->num_vertices, sizeof (nodes_visited));
  if (g && g->num_vertices) {
    res = check_cycle_inner (g, 0, nodes_visited);
  } else {
    res = 0;
  }
  free (nodes_visited);
  return res;
}

int main ()
{
  int i;
  int res;
  struct graph *g1, *g2;
  //Init the graph at https://www.geeksforgeeks.org/detect-cycle-in-a-graph/

  g1 = create_graph (4);
  insert_edge (g1, 0, 1);
  insert_edge (g1, 1, 2);
  insert_edge (g1, 2, 0);
  insert_edge (g1, 0, 2);
  insert_edge (g1, 2, 3);
  insert_edge (g1, 3, 3);
  print_graph (g1);
  res = check_cycle (g1);
  if (res)
    printf ("Cycle exists in g1!!\n");
  else
    printf ("Cycle does not exist in g1!!\n");

  g2 = create_graph (4);
  insert_edge (g2, 0, 1);
  insert_edge (g2, 1, 2);
  insert_edge (g2, 2, 3);
  insert_edge (g2, 0, 2);
//  insert_edge (g, 3, 3);
  print_graph (g2);
  res = check_cycle (g2);
  if (res)
    printf ("Cycle exists in g2!!\n");
  else
    printf ("Cycle does not exist in g2!!\n");
}
