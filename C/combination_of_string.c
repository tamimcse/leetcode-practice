/*
https://www.geeksforgeeks.org/print-all-possible-combinations-of-the-string-by-replacing-with-any-other-digit-from-the-string/
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void combination_of_str_inner (char *str, int *digit, int num_digits, int remaining)
{
  int i, idx_to_set;

  if (!remaining) {
    printf ("%s\n", str);
    return;
  }

  for (i = 0; str[i]; i++) {
    if (str[i] == '$') {
      idx_to_set = i;
      break;
    }
  }

  for (i = 0; i < num_digits; i++) {
    str[idx_to_set] = digit[i];
    combination_of_str_inner (str, digit, num_digits, remaining - 1);
  }
  str[idx_to_set] = '$';
}

void combination_of_str (char *str)
{
  int num_digits, i, j;

  for (i = 0, num_digits = 0; str[i]; i++) {
    if (str[i] != '$')
      num_digits++;
  }

  int *digits = (int *) malloc (num_digits * sizeof (*digits));
  for (i = 0, j = 0; str[i]; i++) {
    if (str[i] != '$')
      digits[j++] = str[i];
  }

  int remaining = strlen(str) - num_digits;
  combination_of_str_inner (str, digits, num_digits, remaining);
}

void main ()
{
  //char str[] = "23$$";
  //char str[] = "$45";
  char str[] = "23$5$$";

  combination_of_str(str); 
}
