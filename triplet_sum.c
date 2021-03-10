/*
Find a triplet that sum to a given value: Given an array and a value, find if there is a triplet in array whose sum is equal to the given value. If there is such a triplet present in array, then print the triplet and return true. Else return false. 

Input: array = {12, 3, 4, 1, 6, 9}, sum = 24;
Output: 12, 3, 9
Explanation: There is a triplet (12, 3 and 9) present
in the array whose sum is 24. 

Input: array = {1, 2, 3, 4, 5}, sum = 9
Output: 5, 3, 1
Explanation: There is a triplet (5, 3 and 1) present 
in the array whose sum is 9. 
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool triplet_sum (int arr[], int len, int target)
{
  int i, j;

  int *hash = (int *) calloc (target, sizeof (*hash));
  for (i = 0; i < len; i++) {
    if (arr[i] < target)
      hash[arr[i]] = 1;
  }

  for (i = 0; i < len; i++) {
    for (j = i + 1; j < len; j++) {
      int to_find = target - arr[i] - arr[j];
      if (hash[to_find]) {
        printf ("Target = %d, output = %d %d %d \n", target, arr[i], arr[j], to_find);
        return true;
      }
    }
  }
  printf ("Triplet not found \n");
  return false;
}

void main ()
{
  int arr [] = {12, 3, 4, 1, 6, 9};
  int len = sizeof (arr) / sizeof (arr[0]);

  triplet_sum (arr, len, 24);
}
