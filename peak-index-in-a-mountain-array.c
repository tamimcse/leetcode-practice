/*
https://leetcode.com/problems/peak-index-in-a-mountain-array/
*/
int peakIndexInMountainArray(int* arr, int arrSize){
  int i;
    
  for (i = 1; i < arrSize - 1; i++) {
    if (arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
      return i;
    }
  }
  return 0;
}
