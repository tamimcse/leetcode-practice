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
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool is_prime (int a)
{
  int i;

  for (i = 2; i <= a/2; i++) {
    if (a % i == 0)
      return false;
  }
  return true;
}

struct edge {
  int v1;
  int v2;
};

struct state {
  int num_vertices;
  int num_edges;
  struct edge edges[12];
  struct state *prev_state;
  int swap_v1;
  int swap_v2;
};

void print_state (struct state *s)
{
  int i;

  for (i = 0; i < 12; i++) {
    printf ("(%d, %d) ", s->edges[i].v1, s->edges[i].v2);
  }
  printf ("\n");
}

//create next state based on swaping the two nodes
struct state *create_next_state (struct state *s, int v1, int v2)
{
  int i;
  struct state *new_state = (struct state *) calloc (1, sizeof (*new_state));
  new_state->num_vertices = s->num_vertices;
  new_state->num_edges = s->num_edges;
  memcpy (new_state->edges, s->edges, sizeof (new_state->edges));
  for (i = 0; i < new_state->num_edges; i++) {
    if (new_state->edges[i].v1 == v1 || new_state->edges[i].v1 == v2) {
      new_state->edges[i].v1 = new_state->edges[i].v1 == v1 ? v2 : v1;
    }
    if (new_state->edges[i].v2 == v1 || new_state->edges[i].v2 == v2) {
      new_state->edges[i].v2 = new_state->edges[i].v2 == v1 ? v2 : v1;
    }
  }
  new_state->prev_state = s;
  new_state->swap_v1 = v1;
  new_state->swap_v2 = v2;
  return new_state;
}

//check if it's the target state
bool check_target (struct state *s)
{
  return ((s->edges[0].v1 == 1 || s->edges[0].v1 == 2) &&
          (s->edges[0].v2 == 1 || s->edges[0].v2 == 2) &&
	  (s->edges[1].v1 == 1 || s->edges[1].v1 == 4) &&
          (s->edges[1].v2 == 1 || s->edges[1].v2 == 4) &&
	  (s->edges[2].v1 == 2 || s->edges[2].v1 == 3) &&
          (s->edges[2].v2 == 2 || s->edges[2].v2 == 3) &&
	  (s->edges[3].v1 == 2 || s->edges[3].v1 == 5) &&
          (s->edges[3].v2 == 2 || s->edges[3].v2 == 5) &&
          (s->edges[4].v1 == 3 || s->edges[4].v1 == 6) &&
          (s->edges[4].v2 == 3 || s->edges[4].v2 == 6) &&
          (s->edges[5].v1 == 4 || s->edges[5].v1 == 5) &&
          (s->edges[5].v2 == 4 || s->edges[5].v2 == 5) &&
          (s->edges[6].v1 == 4 || s->edges[6].v1 == 7) &&
          (s->edges[6].v2 == 4 || s->edges[6].v2 == 7) &&
          (s->edges[7].v1 == 5 || s->edges[7].v1 == 6) &&
          (s->edges[7].v2 == 5 || s->edges[7].v2 == 6) &&
          (s->edges[8].v1 == 5 || s->edges[8].v1 == 8) &&
          (s->edges[8].v2 == 5 || s->edges[8].v2 == 8) &&
          (s->edges[9].v1 == 6 || s->edges[9].v1 == 9) &&
          (s->edges[9].v2 == 6 || s->edges[9].v2 == 9) &&
          (s->edges[10].v1 == 7 || s->edges[10].v1 == 8) &&
          (s->edges[10].v2 == 7 || s->edges[10].v2 == 8) &&
          (s->edges[11].v1 == 8 || s->edges[11].v1 == 9) &&
          (s->edges[11].v2 == 8 || s->edges[11].v2 == 9));
}

void solve_puzzle (struct state *start_state)
{
  int i;
  struct state *curr_state, *nxt_state;
  struct state *queue[10000];
  int start = 0, end = 0;
  struct state *stack[100];
  int stack_idx = 0;

  queue [end++] = start_state;
  while (end > start) {
    curr_state = queue[start++];
    printf ("current state = \n");
    print_state (curr_state);
    for (i = 0; i < curr_state->num_edges; i++) {
      int v1 = curr_state->edges[i].v1;
      int v2 = curr_state->edges[i].v2;
//      printf ("processing node %d and %d !!!!!!\n", v1, v2);
      if (is_prime(v1 + v2)) {
        nxt_state = create_next_state (curr_state, v1, v2);
        if (check_target (nxt_state)) {
          printf ("target is reached !!!!!!\n");
          goto finish;
        } else {
          printf ("swapping %d and %d \n", v1, v2);
          queue [end++] = nxt_state;
        }
      }
    }
  }
  printf ("Target state is not reachable \n");
finish:
  curr_state = nxt_state;
  while (curr_state != start_state) {
    stack[stack_idx++] = curr_state;
    curr_state = curr_state->prev_state;
  }
  while (stack_idx > 0) {
    curr_state = stack[--stack_idx];
    printf ("(%d, %d) ", curr_state->swap_v1, curr_state->swap_v2);
  }
  printf ("\n");
}

void main()
{
  int arr[][3] = {{7, 3, 2}, {4, 1, 5}, {6, 8, 9}};
  int row = sizeof (arr) / sizeof (arr[0]);

  struct state s;
  s.num_vertices = 9;
  s.num_edges = 12;
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

//  print_state (&s);

  solve_puzzle (&s);
}

