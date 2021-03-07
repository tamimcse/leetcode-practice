/*
Minimum spanning tree (MST) - Prim's algorithm.

https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

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

struct node {
  int node_id;
  int weight;
};

struct heap {
  struct node *arr;
  int size;
  int count;
};

struct heap* create_heap (int size)
{
  struct heap* h = (struct heap*) malloc (sizeof (*h));
  h->count = 0;
  h->size = size;
  h->arr = (int *) calloc (size, sizeof (*(h->arr)));
  return h;
}

int minheap_move_up (struct heap* h, int idx)
{
  int chield_idx1, chield_idx2, min_idx;
  struct node tmp; 

  chield_idx1 = (idx << 1) + 1;
  chield_idx2 = (idx << 1) + 2;

  if (chield_idx1 < h->count && h->arr[chield_idx1].weight < h->arr[idx].weight)
    min_idx = chield_idx1;
  else
    min_idx = idx;
  if (chield_idx2 < h->count && h->arr[chield_idx2].weight < h->arr[min_idx].weight)
    min_idx = chield_idx2;

  if (idx != min_idx) {
    tmp = h->arr[idx];
    h->arr[idx] = h->arr[min_idx];
    h->arr[min_idx] = tmp;
    int parent_idx = cell((idx - 2) >> 1);
    minheap_move_up (h, parent_idx);
  }
}

int minheap_insert (struct heap* h, int node_id, int weight)
{
  if (!h || h->count >= h->size)
    return -1;

  heap->arr[count].node_id = node_id;
  heap->arr[count].weight = weight;
  int parent_idx = cell((count - 2) >> 1);
  count++;
  minheap_move_up (h, parent_idx);
  return 0;
}

bool is_heap_empty (struct heap* h)
{
  return !h || h->count == 0;
}

//heapify
void minheap_move_down (struct heap* h, int idx)
{
  struct node tmp;
  int left_idx = (idx << 1) + 1;
  int right_idx = (idx << 1) + 2;
  int smallest_index;
  if (left_idx < h->count && h->arr[idx].weight > h->arr[left_idx].weight)
    smallest_index = left_idx;
  else
    smallest_index = idx;
  if (right_idx < h->count && h->arr[smallest_index].weight > h->arr[right_idx].weight)
    smallest_index = right_idx;

  if (smallest_index != idx) {
    tmp = h->arr[idx];
    h->arr[idx] = h->arr[smallest_index];
    h->arr[smallest_index] = tmp;
    minheap_move_down (h, smallest_index);
  }
}

struct node minheap_delete (struct heap* h)
{
  if (!h || !h->count)
    return -1;
  struct node to_return = h->arr[0];
  h->arr[0] = h->arr[--(h->count)];
  minheap_move_down (h, 0);
  return to_return;
}



void mst_prims (struct graph *g)
{
  int i;
  struct node curr_node;
  struct graph *mst = create_graph (g->num_vertices);  
  int *nodes_visited = (int *) calloc (g->num_vertices, sizeof (*nodes_visited));
  struct heap *h = create_heap (g->num_vertices);
  minheap_insert (h, 0, 0);
  while (is_heap_empty (h)) {
    curr_node = minheap_delete (h);
    nodes_visited[curr_node.node_id] = 1;

    for (i = 0; i < g->num_vertices; i++) {
      int weight = g->adjacency_matrix[curr_node.node_id * g->num_vertices + i];
      if (weight && !nodes_visited[i])
        minheap_insert (h, i, weight);
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
