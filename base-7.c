/*
https://leetcode.com/problems/base-7/
*/
int log7 (int a)
{
  return log10(a) / log10 (7);
}

char * convertToBase7(int num){
  if (!num)
    return "0";
  bool neg = num < 0;
  num = abs (num);
  int num_digit = log7 (num) + 1 + (neg ? 1 : 0);
  char *res = (char *) calloc (num_digit + 1, sizeof (char));
  int i, j, start, end;
  char tmp;
  
  i = 0;
  if (neg)
    res[i++] = '-';
  
  while (num) {
    res[i++] = (num % 7) + '0';
    num /= 7;
  }
  
  start = neg ? 1 : 0;
  end = strlen (res) - 1;
  while (end > start) {
    tmp = res[start];
    res[start] = res[end];
    res[end] = tmp;
    start++;
    end--;
  }
  
  return res;
}
