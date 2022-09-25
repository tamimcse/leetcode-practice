/*
https://leetcode.com/problems/powx-n/

https://www.geeksforgeeks.org/write-a-c-program-to-calculate-powxn/
*/
double myPow(double x, int n){
  double tmp;
  
  if (n == 0)
    return 1;
  if (n == -1)
    return 1/x;
  tmp = myPow (x, n / 2);
  if (n & 1) {
    if (n > 0)
      return tmp * tmp * x;
    else
      return tmp * tmp / x;
  } else {
    return tmp * tmp;
  }
}
