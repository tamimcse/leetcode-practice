/*
Johnny has some difficulty memorizing the small prime numbers. So, his computer science teacher has asked him to play with the following puzzle game frequently.

The puzzle is a 3x3 board consisting of numbers from 1 to 9. The objective of the puzzle is to swap the tiles until the following final state is reached:

1 2 3
4 5 6
7 8 9
At each step, Johnny may swap two adjacent tiles if their sum is a prime
*/
#include <stdio.h>
#include <stdbool.h>

#define SIZE 3

bool is_prime (int a)
{
  int i;

  for (i = 2; i <= a/2; i++) {
    if (a % i == 0)
      return false;
  }
  return true;
}

int distance (int i1, int j1, int i2, int j2)
{
  return abs (i1 - i2) + abs (j1 - j2);
}

void solve_puzzle (int input [][])
{
  int i, j, val, i1, j1, total_distance;
  
  while (1) {
    total_distance = 0;
    for (i = 0; i < SIZE; i++) {
      for (j = 0; j < SIZE; j++) {
        val = input [i][j];
        i1 = (val - 1) / SIZE;
        j1 = (val - 1) % SIZE;
        total_distance += distance (i1, j1, i, j);
      }
    }
    if (!total_distance) {
      printf ("Game ended!!\n");
      break;
    }
  }
}

void main ()
{
  int input [][] = {{7, 3, 2}, {4, 1, 5}, {6, 8, 9}};
}
