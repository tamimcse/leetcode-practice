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

void main ()
{
  char str[] = "I love Kent";
  reverse_words (str);
  printf ("Result is %s \n", str);
}
