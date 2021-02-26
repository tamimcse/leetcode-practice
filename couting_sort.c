/*
Counting sort on an containing characters a-z.
*/
#include <stdio.h>
#include <stdlib.h>

void print (char str [], int size)
{
  int i;

  for (i = 0; i < size; i++) {
    printf ("%c ", str[i]);
  }
  printf ("\n");
}

void counting_sort (char str [], int size, char output [])
{
  //There can be 26 characters
  int count[26] = {0};
  int i;

  for (i = 0; i < size; i++) {
    count[str[i] - 'a']++;
  }

  for (i = 1; i < 26; i++) {
    count [i] += count [i - 1];
  }

  for (i = 0; i < size; i++) {
    output[count[str[i] - 'a'] - 1] = str[i];
    count[str[i] - 'a']--;
  }
}

void main ()
{
  char str [] = {'w', 'w', 'z', 'z', 'b', 'j', 'k', 'a', 'a', 'a'};
  int size = sizeof (str) / sizeof (str[0]);
  char *output = (char *)calloc(size, sizeof (*output));
  counting_sort (str, size, output);
  print (str, size);
  print (output, size);
}
