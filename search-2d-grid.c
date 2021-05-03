/*
https://www.geeksforgeeks.org/search-a-word-in-a-2d-grid-of-characters/
*/
#include <stdio.h>
#include <string.h>

#define NUM_COL 5

void search_grid (char grid[][NUM_COL], int num_row, char *pattern)
{
  int pattern_len = strlen (pattern);
  int i, j, k, row, col;

  for (i = 0; i < num_row; i++) {
    for (j = 0; j < NUM_COL; j++) {
      if (grid[i][j] != pattern[0])
        continue;
      //check horizontallty
      for (row = i, col = j + 1, k = 1; k < pattern_len && col < NUM_COL; k++, col++) {
        if (grid[row][col] != pattern[k])
          break;
      }
      if (k == pattern_len)
        printf ("Horizontal match found at (%d, %d) \n", i, j);
      //check verically
      for (row = i + 1, col = j, k = 1; k < pattern_len && row < num_row; k++, row++) {
        if (grid[row][col] != pattern[k])
          break;
      }
      if (k == pattern_len)
        printf ("Vertical match found at (%d, %d) \n", i, j);
      //Diagonally right
      for (row = i + 1, col = j + 1, k = 1; k < pattern_len && row < num_row && col < NUM_COL; k++, row++, col++) {
        if (grid[row][col] != pattern[k])
          break;
      }
      if (k == pattern_len)
        printf ("Diagonal right match found at (%d, %d) \n", i, j);
      //Diagonally left
      for (row = i + 1, col = j - 1, k = 1; k < pattern_len && row < num_row && col >= 0; k++, row++, col--) {
        if (grid[row][col] != pattern[k])
          break;
      }
      if (k == pattern_len)
        printf ("Diagonal left match found at (%d, %d) \n", i, j);
      //Diagonally up left
      for (row = i - 1, col = j - 1, k = 1; k < pattern_len && row >= 0 && col >= 0; k++, row--, col--) {
        if (grid[row][col] != pattern[k])
          break;
      }
      if (k == pattern_len)
        printf ("Diagonal up left match found at (%d, %d) \n", i, j);
      //Diagonally up right
      for (row = i - 1, col = j + 1, k = 1; k < pattern_len && row >= 0 && col < NUM_COL; k++, row--, col++) {
        if (grid[row][col] != pattern[k])
          break;
      }
      if (k == pattern_len)
        printf ("Diagonal up right match found at (%d, %d) \n", i, j);
    }
  }
  
}

void main ()
{
  char grid[][NUM_COL] = {"cinci", "iittc", "ncnna", "ccici", "icini"};
  int num_row = sizeof (grid) / sizeof (grid[0]);
  char pattern[] = "cin";

  search_grid (grid, num_row, pattern);
}
