/*
Minimum spanning tree (MST) using kruskal's algoritgm
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct edge {
  int id;
  int v1;
  int v2;
  int weight;
};

struct graph {
  int num_vertices;
  int num_edges;
  struct edge *edges;
};

struct graph1 {
  int num_vertices;
  int num_edges;
  //adjacency matrix
  struct edge **ad_matrix;
};

struct graph *create_graph (int v, int e)
{
  struct graph *g = (struct graph *) malloc (sizeof (*g));
  g->num_vertices = v;
  g->num_edges = e;
  g->edges = (struct edge *) calloc (g->num_edges, sizeof (*g->edges));
  return g;
}

struct graph1 *create_graph1 (int v, int e)
{
  struct graph1 *g = (struct graph1 *) malloc (sizeof (*g));
  g->num_vertices = v;
  g->num_edges = e;
  g->ad_matrix = (struct edge **) calloc (g->num_vertices * g->num_vertices, sizeof (*g->ad_matrix));
  return g;
}

int insert_edge (struct graph *g, int idx, int i, int j, int weight)
{
  struct edge *runner;

  if (i >= g->num_vertices || j >= g->num_vertices || idx >= g->num_edges)
    return 1;

  g->edges[idx].id = idx;
  g->edges[idx].v1 = i;
  g->edges[idx].v2 = j;
  g->edges[idx].weight = weight;

  return 0;
} 

int edge_cmp (const void *e1, const void *e2) {
   return ((struct edge *)e1)->weight - ((struct edge *)e2)->weight;
}

int check_cycle_inner (struct graph1 *g, int start_vertex, int *vertices_visited, int *edges_visited)
{
  int i;
  struct edge *e;
  int other_vertex;
  int res;
  printf ("visiting vertex %d\n", start_vertex);

  //cycle detected
  if (vertices_visited[start_vertex])
    return 1;

  //mark it visited
  vertices_visited[start_vertex] = 1;

  for (i = 0; i < g->num_vertices; i++) {
    e = g->ad_matrix[start_vertex * g->num_vertices + i];
    if (e && !edges_visited[e->id]) {
      edges_visited[e->id] = 1;
      //get the other vertex
      other_vertex = (e->v1 == start_vertex) ? e->v2 : e->v1;
      res = check_cycle_inner (g, other_vertex, vertices_visited, edges_visited);
      if (res)
        return res;
    }
  }
  //unmark it
  vertices_visited[start_vertex] = 0;
  return 0;
}

int check_cycle (struct graph1 *g, int start_vertex)
{
  int res = 0;
  int *vertex_visited = (int *) calloc (g->num_vertices, sizeof (*vertex_visited));
  int *edges_visited = (int *) calloc (g->num_edges, sizeof (*edges_visited));

  printf ("Checking start_vertex %d\n", start_vertex);
  res = check_cycle_inner (g, start_vertex, vertex_visited, edges_visited);
  free (vertex_visited);
  free (edges_visited);
  printf ("\n");
  return res;
}
 
void kruskal_mst (struct graph *g)
{
  int i, j;
  struct edge *e;
  //new graph which will be MST
  struct graph1 *g1 = create_graph1 (g->num_vertices, g->num_edges);

  //sort the edges
  qsort (g->edges, g->num_edges, sizeof (*g->edges), edge_cmp);

  //This array keeps track of the vertices that have been added to MST
  int *vertices_added = (int *) calloc (g->num_vertices, sizeof (*vertices_added));
  for (i = 0; i < g->num_edges; i++) {
    //add the edge to new adjacency matrix
    g1->ad_matrix[g->edges[i].v1 * g->num_vertices + g->edges[i].v2] = &g->edges[i];
    g1->ad_matrix[g->edges[i].v2 * g->num_vertices + g->edges[i].v1] = &g->edges[i];
    //check if adding the edge makes a cycle; if yes, remove the edge
    if (check_cycle (g1, g->edges[i].v1)) {
      g1->ad_matrix[g->edges[i].v1 * g->num_vertices + g->edges[i].v2] = 0;
      g1->ad_matrix[g->edges[i].v2 * g->num_vertices + g->edges[i].v1] = 0;
    } else {
      vertices_added[g->edges[i].v1] = 1;
      vertices_added[g->edges[i].v2] = 1;
      //check if all the vertices have been added
      for (j = 0; j < g->num_vertices; j++) {
        if (!vertices_added[j])
          break;
      }
      //MST has been constructed
      if (j == g->num_vertices)
        break;
    }
  }

  printf ("MST = \n");
  for (i = 0; i < g1->num_vertices; i++) {
    for (j = 0; j < g1->num_vertices; j++) {
      e = g1->ad_matrix[i * g1->num_vertices + j];
      if (e) {
        printf ("%d->%d:%d\n", e->v1, e->v2, e->weight);
      }
    }
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
  kruskal_mst (g);
}
