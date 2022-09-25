/*
https://leetcode.com/problems/daily-temperatures/

https://www.geeksforgeeks.org/count-of-days-remaining-for-the-next-day-with-higher-temperature/

Note that, brutforce is O(n^2) where as using stack makes in O(n).
*/



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize){
  int *res = (int *) malloc (temperaturesSize * sizeof (int));
  *returnSize = temperaturesSize;
  int *stack = (int *) malloc (temperaturesSize * sizeof (int));
  int i, j, s_idx = 0;
  
  for (i = 0; i < temperaturesSize; i++) {
    while (s_idx >= 1 && temperatures[i] > temperatures[stack[s_idx-1]]) {
      res[stack[s_idx-1]] = i - stack[s_idx-1];
      s_idx--;
    }
    stack[s_idx++] = i;
  }
  
  while (s_idx >= 1) {
    res[stack[--s_idx]] = 0;  
  }
  
  return res;
}
