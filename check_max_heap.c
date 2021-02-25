/*
Check if an array is a max heap or not. In a max heap, each node is greater than its decendents.

Input:  arr[] = {90, 15, 10, 7, 12, 2}
Output: True
The given array represents below tree
       90
     /    \
   15      10
  /  \     /
7    12  2
The tree follows max-heap property as every
node is greater than all of its descendants. 

Input:  arr[] = {9, 15, 10, 7, 12, 11}
Output: False
The given array represents below tree
       9
     /    \
   15      10
  /  \     /
7    12  11
The tree doesn't follows max-heap property 9 is
smaller than 15 and 10, and 10 is smaller than 11.
*/
#include <stdio.h>

int check_max_heap (int a[], int size)
{
  int i, child1_idx, child2_idx;

  for (i = 0; i < size; i++) {
    child1_idx = (i << 2) + 1;
    child2_idx = (i << 2) + 2;
    if ((child1_idx < size && a[i] < a[child1_idx]) || 
        (child2_idx < size && a[i] < a[child2_idx]))
      return 0;
  }
  return 1;
}

void main ()
{
  int a [] = {90, 15, 10, 7, 12, 2};
  int b [] = {9, 15, 10, 7, 12, 11};

  if (check_max_heap (a, sizeof (a)/sizeof (a[0])))
    printf ("a is a heap\n");
  else
    printf ("a is not a heap\n");

  if (check_max_heap (b, sizeof (b)/sizeof (b[0])))
    printf ("b is a heap\n");
  else
    printf ("b is not a heap\n");
}
