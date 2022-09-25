/*
https://www.geeksforgeeks.org/nuts-bolts-problem-lock-key-problem-set-2-hashmap/
*/
#include <stdio.h>


void match (char *nuts, char *bolts)
{
  int i;
  int hash[256] = {0};
  int nuts_len = sizeof (nuts) / sizeof (nuts[0]);
  int bolts_len = sizeof (bolts) / sizeof (bolts[0]);

  for (i = 0; i < nuts_len; i++)
    hash[nuts[i]] = 1;

  for (i = 0; i < bolts_len; i++) {
    if (hash[bolts[i]]) {
      printf ("%c ", bolts[i]);
    }
  }
  printf ("\n");
}

void main ()
{
  char nuts[] = {'@', '#', '$', '%', '^', '&'};
  char bolts[] = {'$', '%', '&', '^', '@', '#'};

  match (nuts, bolts);
}
