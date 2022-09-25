/*
https://leetcode.com/problems/confusing-number/
*/
int confunsing[10] = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};

bool confusingNumber(int n){
  int digit, res = 0, tmp = n;
  
  while (tmp) {
    digit = tmp % 10;
    if (confunsing[digit] == -1)
      return false;
    res = res * 10 + confunsing[digit];
    tmp /= 10;
  }
  return n != res;
}
