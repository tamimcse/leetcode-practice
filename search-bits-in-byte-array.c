/*
https://stackoverflow.com/questions/2943632/how-to-search-n-bits-in-a-byte-array
*/
#include <stdio.h>

int search (int *arr, int arr_len, int pattern, int pattern_len)
{
  int i, j;
  int mask, curr, count = 0;

  for (i = arr_len - 1; i >= 0; i--) {
    curr = arr[i];
    mask = (1 << pattern_len) - 1;
    for (j = 0; j <= 8 - pattern_len; j++) {
      if ((curr & mask) >> j == pattern)
        count++;
      mask <<= 1; 
    }
    
    //leftmost byte
    if (i == 0)
      continue;

    //matching boundary
    int left = arr[i - 1];    
    for (j = 0; j < pattern_len - 1; j++) {
      curr >>= 1;
      if (left & 1)
        curr |= (1 << 7);
      left >>= 1;
      if ((curr >> (8 - pattern_len)) == pattern)
        count++;
    }
  }
  return count; 
}

void main ()
{
  int pattern = 11;
  int pattern_len = 4;
  int arr[] = {186, 236};
  int arr_len = sizeof (arr) / sizeof (arr[0]);

  int res = search (arr, arr_len, pattern, pattern_len);

  printf ("The result is %d \n", res);
}
