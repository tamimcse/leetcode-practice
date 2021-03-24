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

struct state {
  int arr[3][3];
  int g;
  int h;
  long unsigned int prev_state;
  int swap_v1;
  int swap_v2;
  struct state *next;
};

#define NUM_VERTICES (1ULL << 36)

struct state vertices[NUM_VERTICES]; 

long unsigned long hash (char arr[][3])
{
  int i, j;
  long unsigned long hash_idx = 0;

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      hash_idx = (hash_idx << 4) | arr[i][j];
    }
  }
  return hash_idx;
}

int huristic (char arr[][3])
{
  int distance = 0;
  int i, j;

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      switch (arr[i][j]) {
        case 1:
          distance += abs (i - 0) + abs (j - 0);
          break;
        case 2:
          distance += abs (i - 0) + abs (j - 1);
          break;
        case 3:
          distance += abs (i - 0) + abs (j - 2);
          break;
        case 4:
          distance += abs (i - 1) + abs (j - 0);
          break;
        case 5:
          distance += abs (i - 1) + abs (j - 1);
          break;
        case 6:
          distance += abs (i - 1) + abs (j - 2);
          break;
        case 7:
          distance += abs (i - 2) + abs (j - 0);
          break;
        case 8:
          distance += abs (i - 2) + abs (j - 1);
          break;
        case 9:
          distance += abs (i - 2) + abs (j - 2);
          break;
      }
    }
  }
  return (distance >> 1);
}

void solve_puzzle (char arr[][3]) {
  struct state *vertices = (struct state *) calloc (NUM_VERTICES, sizeof (*vertices));
  struct state *open_list = NULL;

  long unsigned long idx = hash (arr);
  memcpy (vertices[idx].arr, arr, sizeof (arr));
  vertices[idx].g = 0;
  vertices[idx].h = 0;
}

void main (void)
{
  char arr[][3] = {{7, 3, 2}, {4, 1, 5}, {6, 8, 9}};
}
