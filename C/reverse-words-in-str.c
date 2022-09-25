/*
https://www.geeksforgeeks.org/reverse-words-in-a-given-string/
*/
#include <string.h>
#include <stdio.h>

void reverse_word (char *str, int start, int end)
{
  int i, j, tmp;

  for (i = start, j = end; j > i; i++, j--) {
    tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
  }
}

void reverse_words (char *str)
{
  int i, j, len = strlen (str), tmp;

  reverse_word (str, 0, len - 1);

  for (i = 0, j = 0; i < len; ) {
    if (str[j] != ' ' && str[j]) {
      j++;
    } else {
      reverse_word (str, i, j - 1);
      j++;
      i = j;
    }
  }

}

//check beneath main
void main ()
{
  char str[] = "I love Kent";
  reverse_words (str);
  printf ("Result is %s \n", str);
}

/*
https://leetcode.com/problems/reverse-words-in-a-string/

char * reverseWords(char * s){
  int i, j, k, len = strlen (s), start, end, m, n;
  bool ignore_space = true;
  char tmp;

  
  for (i = 0, k = 0; s[i]; i++) {
    if (ignore_space && s[i] == ' ')
      continue;
    s[k++] = s[i];
    if (s[i] == ' ')
      ignore_space = true;
    else
      ignore_space = false;
  }
  if (k > 0 && s[k-1] == ' ')
    s[--k] = '\0';
  else
    s[k] = '\0';
  
  for (i = 0, j = k - 1; i < j; i++, j--) {
    tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
  }
  
  for (i = 0, start = 0; i <= k; i++) {
    if (s[i] == ' ' || s[i] == '\0') {
      end = i - 1;
      for (m = start, n = end; n > m; m++, n--) {
        tmp = s[m];
        s[m] = s[n];
        s[n] = tmp;
      }
      start = i + 1;
    }
  }
  return s;
}
*/
