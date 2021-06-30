/*
https://leetcode.com/problems/happy-number/

https://www.geeksforgeeks.org/happy-number/
*/
int next_num (int n)
{
  int sum = 0, digit;
  while (n) {
    digit = n % 10;
    n = n / 10;
    sum += (double)digit * digit;
  }
  return sum;
}

bool isHappy(int n){
  if (n == 1)
    return true;
  
  int slow = n, fast = n;
  int next1, next2;
  while (1) {
    slow = next_num (slow);
    fast = next_num (next_num (fast));
    if (slow == 1)
      return true;
    if (slow == fast)
      return false;
  }
}
