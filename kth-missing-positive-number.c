/*
https://leetcode.com/problems/kth-missing-positive-number/
*/


int findKthPositive(int* arr, int arrSize, int k){
  int i, j, count = 0;
  
  i = 1;
  j = 0;
  while (1) {
    if (j < arrSize && i == arr[j]) {
      j++;
    } else {
      count++;
      if (count == k)
        return i;
    }
    i++;
  }
  return 0;
}
