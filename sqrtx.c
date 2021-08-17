/*
https://leetcode.com/problems/sqrtx/
*/


int mySqrt(int x){
  long start = 0, end = x / 2, mid;
  
  
  while (start <= end) {
    mid = (start + end) >> 1;
    if (x >= (mid * mid) && x < (mid + 1) * (mid + 1)) {
      return mid;  
    } else if (x >= (mid + 1) * (mid + 1)) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return x;
}
