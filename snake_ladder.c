/*
Snake and Ladder Problem: Given a snake and ladder board, find the minimum number of dice throws required to reach the destination or last cell from source or 1st cell. Basically, the player has total control over outcome of dice throw and wants to find out minimum number of throws required to reach last cell.

https://www.geeksforgeeks.org/snake-ladder-problem-2/
*/
#include <stdio.h>
#include <stdlib.h>

#define SIZE 30

struct edge {
  int v1;
  int v2;
  struct edge *next;
};

struct graph {
  int num_vertices;
  int num_edges;
  struct edge **adj_list;
};

int insert_edge(struct graph *g, int v1, int v2)
{
  if (v1 >= g->num_vertices || v2 >= g->num_vertices)
    return -1;

  struct edge *new_edge = (struct edge *) malloc (sizeof (*new_edge));
  new_edge->v1 = v1;
  new_edge->v2 = v2;
  new_edge->next = g->adj_list[v1];
  g->adj_list[v1] = new_edge;
  g->num_edges++;
  return 0;
}

void print_graph (struct graph *g)
{
  int i;
  struct edge *runner = NULL;

  printf ("Number of vertices %d\n", g->num_vertices);
  printf ("Edges: \n");
  for (i = 0; i < g->num_vertices; i++) {
    runner = g->adj_list[i];
    while (runner) {
      printf ("%d->%d ", runner->v1, runner->v2);
      runner = runner->next;
    }
    printf ("\n");
  }
}


int snake_ladder (int move[], int size)
{
  int i, j;
  struct graph g;
  g.num_vertices = size;
  g.num_edges = 0;
  g.adj_list = (struct edge **) calloc (g.num_vertices, sizeof (*g.adj_list));

  for (i = 0; i < SIZE; i++) {
    for (j = 1; j <= 6; j++) {
      if (i + j >= SIZE)
        continue;
      if (move[i + j] == -1)
        insert_edge (&g, i, i + j);
      else
        insert_edge (&g, i, move[i + j]);
    }
  }

  print_graph(&g);
}

void main ()
{
  int moves[SIZE];
  int i;

  for (i = 0; i < SIZE; i++)
    moves[i] = -1;

  // Ladders 
  moves[2] = 21; 
  moves[4] = 7; 
  moves[10] = 25; 
  moves[19] = 28; 
  
  // Snakes 
  moves[26] = 0; 
  moves[20] = 8; 
  moves[16] = 3; 
  moves[18] = 6; 

  snake_ladder (moves, SIZE);
}
