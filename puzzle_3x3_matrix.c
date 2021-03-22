/*
You were given a 3×3 matrix consisting of numbers between 1- 9. Finally, you have to arrange the matrix in the following format
1 2 3
4 5 6
7 8 9
In the original matrix, only the following operations were allowed to convert the matrix.
Operation – You can exchange two adjacent numbers only if their sum is a prime number.
Find the minimum number of exchanges needed to reach the final(goal) matrix.
*/
#include <stdio.h>

struct edge {
  int v1;
  int v2;
};

struct state {
  int num_vertices;
  int number_edges;
  struct edge edges[12];
};

void print_state (struct state *s)
{
  int i;

  for (i = 0; i < 12; i++) {
    printf ("(%d, %d) ", s->edges[i].v1, s->edges[i].v2);
  }
  printf ("\n");
}

void main()
{
  int arr[][3] = {{7, 3, 2}, {4, 1, 5}, {6, 8, 9}};
  int row = sizeof (arr) / sizeof (arr[0]);

  struct state s;
  s.num_vertices = 9;
  s.number_edges = 12;
  s.edges[0] = (struct edge){arr[0][0], arr[0][1]};
  s.edges[1] = (struct edge){arr[0][0], arr[1][0]};
  s.edges[2] = (struct edge){arr[0][1], arr[0][2]};
  s.edges[3] = (struct edge){arr[0][1], arr[1][1]};
  s.edges[4] = (struct edge){arr[0][2], arr[1][2]};
  s.edges[5] = (struct edge){arr[1][0], arr[1][1]};
  s.edges[6] = (struct edge){arr[1][0], arr[2][0]};
  s.edges[7] = (struct edge){arr[1][1], arr[1][2]};
  s.edges[8] = (struct edge){arr[1][1], arr[2][1]};
  s.edges[9] = (struct edge){arr[1][2], arr[2][2]};
  s.edges[10] = (struct edge){arr[2][0], arr[2][1]};
  s.edges[11] = (struct edge){arr[2][1], arr[2][2]};

  printf ("row = %d \n", row);

  print_state (&s);
}

