/*
https://leetcode.com/problems/is-graph-bipartite/

https://www.geeksforgeeks.org/bipartite-graph/
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool is_bipartite(int** graph, int graphSize, int* graphColSize){
  int *queue = (int *) calloc (graphSize * graphSize, sizeof (*queue));
  int q_start = 0, q_end = 0;
  int *color = (int *) calloc (graphSize, sizeof (*color));
  int *visited = (int *) calloc (graphSize, sizeof (*visited));
  int curr_node, i, j, adj_node;

  for (j = 0; j < graphSize; j++) {
    if (visited[j])
      continue;
    color[j] = 1;
    q_end = 0;
    q_start = 0;
    queue[q_end++] = j;
    while (q_end > q_start) {
      curr_node = queue[q_start++];
      if (visited[curr_node])
        continue;
      visited[curr_node] = 1;
      for (i = 0; i < graphColSize[curr_node]; i++) {
        adj_node = graph[curr_node][i];
        if (visited[adj_node])
          continue;
        if (color[curr_node] == color[adj_node])
          return false;
        color[adj_node] = (color[curr_node] == 1) ? 2 : 1;
        queue[q_end++] = adj_node; 
      }
    }
  }

  return true;
}

void main ()
{
  int i, graph_size = 5, j;
  int **graph = (int **) calloc (graph_size, sizeof (*graph));
  int col_size[] = {2, 2, 3, 3, 2};
  for (i = 0; i < graph_size; i++) {
    graph[i] = (int *) calloc (col_size[i], sizeof (*graph[i]));
  }

  graph[0][0] = 1;
  graph[0][1] = 3;

  graph[1][0] = 0;
  graph[1][1] = 2;

  graph[2][0] = 1;
  graph[2][1] = 3;
  graph[2][2] = 4;

  graph[3][0] = 0;
  graph[3][1] = 2;
  graph[3][2] = 4;

  graph[4][0] = 2;
  graph[4][1] = 3;

  bool res = is_bipartite (graph, graph_size, col_size);
  printf ("The graph %s bipartite\n", res ? "is" : "is not");
 
}
