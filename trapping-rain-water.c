/*
https://leetcode.com/problems/trapping-rain-water/

https://www.geeksforgeeks.org/trapping-rain-water/

Very interesting problem!!! This is not DP!! :-)
*/



int trap(int* height, int heightSize){
  int start = 0, end = heightSize - 1, i, j, sum = 0, max;
  int *stack = (int *) malloc ((end - start + 1) * sizeof (int));
  int idx = 0;  
      
  while (start + 1 <= end && height[start+1]  > height[start]) {
    start++;  
  }
    
  while (end - 1 >= 0 && height[end-1]  > height[end]) {
    end--;  
  }
  
  stack[idx++] = height[start]; 
  for (i = start + 1; i <= end; i++) {
    if (height[i] >= stack[0]) {
      for (j = 0; j < idx; j++) {
        sum += (stack[0] - stack[j]);
      }
      stack[0] = height[i];
      idx = 1;
    } else {
        stack[idx++] = height[i];
    }  
  }
    
  if (idx > 1) {
    max = stack[idx - 1];
    for (i = idx - 2; i >= 0; i--) {
      if (stack[i] <= max) {
        sum += (max - stack[i]);  
      } else {
        max = stack[i];  
      }   
    }  
  }
  
  return sum;  
}

/*

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

*/
