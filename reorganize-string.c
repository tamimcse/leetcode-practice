/*
https://leetcode.com/problems/reorganize-string/

https://www.geeksforgeeks.org/rearrange-characters-string-no-two-adjacent/

Both solution of geeksforgeeks are elegant.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct elem {
  char ch;
  int cnt;
};

void heapify (struct elem *heap, int size, int idx)
{
  int left_idx = (idx << 1) + 1, right_idx = (idx << 1) + 2;
  int largest_child_idx = -1;
  struct elem tmp;

  if (left_idx < size)
    largest_child_idx = left_idx;
  if (right_idx < size && heap[right_idx].cnt > heap[largest_child_idx].cnt)
    largest_child_idx = right_idx;
  if (largest_child_idx >= 0 && heap[largest_child_idx].cnt > heap[idx].cnt) {
    tmp = heap[idx];
    heap[idx] = heap[largest_child_idx];
    heap[largest_child_idx] = tmp;
    heapify (heap, size, largest_child_idx);
  }
}

void push_up (struct elem *heap, int size, int idx)
{
  if (!idx)
    return;
  int parent_idx = (idx - 1) >> 1;
  int left_idx = (parent_idx << 1) + 1, right_idx = (parent_idx << 1) + 2;
  int largest_child_idx = -1;
  struct elem tmp;

  if (left_idx < size)
    largest_child_idx = left_idx;
  if (right_idx < size && heap[right_idx].cnt > heap[largest_child_idx].cnt)
    largest_child_idx = right_idx;
  if (largest_child_idx >= 0 && heap[largest_child_idx].cnt > heap[parent_idx].cnt) {
    tmp = heap[parent_idx];
    heap[parent_idx] = heap[largest_child_idx];
    heap[largest_child_idx] = tmp;
    push_up (heap, size, parent_idx);
  }
}

char * reorganizeString(char * s){
  int i, j, k;
  struct elem heap[26];
  struct elem tmp_elem1, tmp_elem2;
  int len = strlen (s);
  char *res = (char *) malloc ((len + 1) * sizeof (char));

  for (i = 0; i < 26; i++) {
    heap[i].ch = 'a' + i;
    heap[i].cnt = 0;
  }

  for (i = 0; s[i]; i++) {
    heap[s[i]-'a'].cnt++;
  }
  //Builds the heap starting from the last parent
  for (i = 25 >> 1; i >= 0; i--) {
    heapify (heap, 26, i);
  } 
  for (i = 0; i < len; i += 2) {
    res[i] = heap[0].ch;
    tmp_elem1 = heap[0];
    tmp_elem1.cnt--;
    heap[0] = heap[25];
    heapify (heap, 25, 0);
    if (s[i+1]) {
      res[i+1] = heap[0].ch;
      tmp_elem2 = heap[0];
      tmp_elem2.cnt--;
      heap[0] = heap[24];
      heapify (heap, 24, 0);
      heap[24] = tmp_elem1;
      push_up (heap, 25, 24);
      heap[25] = tmp_elem2;
      push_up (heap, 26, 25);
    }
  }
  res[len] = '\0';
  return res;
}

void main ()
{
  char str[] = "aabbcaad";
  char *res = reorganizeString (str);
  printf ("Result = %s \n", res);
}
