/*
https://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/
*/
#include <stdio.h>

void search (int mat[][4], int target)
{
  int x = 0, y = 3;
  
  while (x >= 0 && y >= 0) {
    if (mat[x][y] == target) {
      printf ("%d is found at %d, %d \n", target, x, y);
      return;
    } else if (target > mat[x][y]) {
      x++;
    } else {
      y--;
    }
  }
  printf ("%d is not found \n", target);
}

void main ()
{
  int mat[4][4] = { {10, 20, 30, 40},
                      {15, 25, 35, 45},
                      {27, 29, 37, 48},
                      {32, 33, 39, 50}};

  search (mat, 29);
  search (mat, 100);
  search (mat, 10);
  search (mat, 32);
  search (mat, 50);
  search (mat, 55);

}
