/*
https://leetcode.com/problems/find-k-closest-elements/

Interesting problem
*/

int cmp (const void *a, const void *b)
{
  return *((int *)a) - *((int *)b);
}

bool less_than (int x, int a, int b)
{
  if (abs (a - x) < abs (b - x))
    return true;
  if (abs (a - x) == abs (b - x) && a < b)
    return true;
  return false;
}

int find_first (int *arr, int len, int x)
{
  int start, end, mid;
  
  if (x < arr[0])
    return 0;
  if (x > arr[len-1])
    return len-1;
  
  start = 0;
  end = len - 1;
  while (start < end) {
    mid = (start + end) >> 1;
    if (arr[mid] == x)
      return mid;
    if (x > arr[mid]) {
      start = mid + 1;
      if (less_than (x, arr[mid], arr[start]))
        return mid;
    } else {
      end = mid - 1;
      if (less_than (x, arr[mid], arr[end]))
        return mid;
    }
  }
  return start;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findClosestElements(int* arr, int arrSize, int k, int x, int* returnSize){
  int *res = (int *) malloc (k * sizeof (int));
  int res_cnt = 0;
  int left, right;
  *returnSize = k;
  
  
  left = find_first (arr, arrSize, x);
  right = left;
  printf ("left = %d \n", arr[left]);
  res[res_cnt++] = arr[left];
  for (; res_cnt < k; res_cnt++) {
    if (left == 0) {
      res[res_cnt] = arr[right + 1];
      right++;      
      continue;
    }
    if (right == arrSize - 1) {
      res[res_cnt] = arr[left-1];
      left--;
      continue;      
    }
      
    if (less_than (x, arr[left - 1], arr[right + 1])) {
      res[res_cnt] = arr[left-1];
      left--;
    } else {
      res[res_cnt] = arr[right + 1];
      right++;      
    }
  }
  
  qsort (res, k, sizeof (int), cmp);
  
  return res;
}
