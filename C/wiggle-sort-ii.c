/*
https://leetcode.com/problems/wiggle-sort-ii/

Tried to solve in place. Look simple, but toooo tough!!

Take a look at the note for details
*/
void swap (int *arr, int i, int j)
{
  int tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

int cmp (const void *a, const void *b)
{
  return *((int *)a) - *((int *)b);
}

void wiggleSort(int* nums, int numsSize){
  int num_large_elements = numsSize >> 1;
  int i, j, k;
  int *tmp = (int *) malloc (numsSize * sizeof (*tmp));
  
  if (numsSize <= 1) {
    return;
  }
  memcpy (tmp, nums, numsSize * sizeof (*tmp));
  qsort (tmp, numsSize, sizeof (int), cmp);
  
  for (i = numsSize - num_large_elements - 1, j = numsSize - 1, k = 0;
       k < numsSize; k++) {
    if (k & 1) {
      nums[k] = tmp[j--];
    } else {
      nums[k] = tmp[i--];
    }
  }
}
