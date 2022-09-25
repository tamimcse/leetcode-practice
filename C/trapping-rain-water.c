/*
https://leetcode.com/problems/trapping-rain-water/

https://www.geeksforgeeks.org/trapping-rain-water/

Very interesting problem!!! This is not DP!! :-)

Try to find out the approach without looking at the solution. 

My apprach is: if you find a taller wall than current wall, you find that the border. We can implement this using stack. Push each element to stack until you find an element larger than the first element. If you find an element larger than the first element, pop all the element and calculate the sum. Now this approach will work for following case:

             |
|            |
|  |         |
|  |      |  |  
---------------------

But, it will not work for :

|             
|            |
|  |         |
|  |      |  |     |
---------------------

In this case, stack will have a whole bunch of elements, but they will not be popped. Now, you can solve this in following way. Note that, the problem is same as the previous one, but from right to left. So, keep track of the max = right_most_element and iterate from right to left. Everytime you find an element than is larger than max, you calculate the sum for the boundaries 
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
