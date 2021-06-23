/*
https://leetcode.com/problems/trapping-rain-water/

https://www.geeksforgeeks.org/trapping-rain-water/

Very interesting problem!!! This is not DP!! :-)
*/
int trap(int* height, int heightSize){
  int i, j, sum;
  int *left = (int *) malloc (heightSize * sizeof (*left));
  int *right = (int *) malloc (heightSize * sizeof (*right));
  
  if (!heightSize)
    return 0;
  
  left[0] = height[0];
  for (i = 1; i < heightSize; i++) {
    left[i] = left[i-1] > height[i] ? left[i-1] : height[i];
  }
  
  right[heightSize-1] = height[heightSize-1];
  for (i = heightSize-2; i >= 0; i--) {
    right[i] = right[i+1] > height[i] ? right[i+1] : height[i];
  }
  
  sum = 0;
  for (i = 0; i < heightSize; i++) {
    sum += (left[i] <= right[i]) ? left[i] - height[i] : right[i] - height[i]; 
  }
  return sum;
}
