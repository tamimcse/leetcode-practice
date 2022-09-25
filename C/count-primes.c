/*
https://leetcode.com/problems/count-primes/
*/

bool is_prime (int n)
{
  if (n == 0 || n == 1)
    return false;
  if (n == 2 || n == 3)
    return true;
  int i;
  
  for (i = 2; i <= sqrt(n); i++) {
    if (n % i == 0)
      return false;
  }
  return true;
}

int countPrimes(int n){
  int i, j, count;
  
  if (n <= 1)
    return 0;
  
  int *arr = (int *)calloc(n, sizeof (*arr));
  
  for (i = 0; i <= sqrt (n); i++) {
    if (!is_prime (i))
      arr[i] = 1;
  }
  
  for (i = 2; i <= sqrt (n); i++) {
    if (arr[i])
      continue;
    for (j = i * 2; j < n; j += i) {
      arr[j] = 1;
    }
  }
  
  count = 0;
  for (i = 0; i < n; i++) {
    if (!arr[i])
      count++;
  }
  return count;
}
