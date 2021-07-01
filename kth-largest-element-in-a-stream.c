/*
https://leetcode.com/problems/kth-largest-element-in-a-stream/
*/

int cmp (const void *a, const void *b)
{
  return *((int *)a) - *((int *)b);
}

typedef struct {
  int *arr;
  int size;
  int k;
} KthLargest;


KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
  qsort (nums, numsSize, sizeof (int), cmp);
  KthLargest *arr = (KthLargest *) malloc (sizeof (*arr));
  arr->k = k;
  arr->size = k;
  arr->arr = (int *) malloc (k * sizeof (int));
  if (numsSize >= k) {
    memcpy (arr->arr, nums + (numsSize  - k), k * sizeof (int));
  } else {
    for (int i = 0; i < k - numsSize; i++)
      arr->arr[i] = -100001;
    memcpy (arr->arr + k  - numsSize, nums, numsSize * sizeof (int));
  }
  return arr;
}

int kthLargestAdd(KthLargest* obj, int val) {
  int i;
  if (val > obj->arr[0]) {
    for (i = 1; i < obj->k; i++) {
      if (obj->arr[i] < val) {
        obj->arr[i-1] = obj->arr[i];
      } else {
        break;
      }
    }
    obj->arr[i-1] = val;
  }
  return obj->arr[0];
}

void kthLargestFree(KthLargest* obj) {
  free (obj->arr);
  free (obj);
}

/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);
 
 * kthLargestFree(obj);
*/
