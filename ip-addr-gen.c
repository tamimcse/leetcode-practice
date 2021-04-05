/*
https://practice.geeksforgeeks.org/problems/generate-ip-addresses/1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


bool is_valid_ip (char *str, char *dot)
{
  int i, j, off = 0, last_dot_idx = -1;

  for (i = 0; str[i+1]; i++) {
    if (dot[i]) {
      if (i - last_dot_idx > 3)
        return false;
      last_dot_idx = i;
    }
  }
  if (i - last_dot_idx > 3)
    return false;
  return true;
}

void ip_addr_gen_inner (char *str, char *dot, int num_dot)
{
  int i, j;

  if (num_dot == 3) {
    if (!is_valid_ip (str, dot))
      return;
    for (i = 0; i < str[i]; i++) {
      printf ("%c", str[i]);
      if (dot[i])
        printf (".");
    }
    printf ("\n");
    return;
  }

  for (i = 0; str[i+1]; i++) {
    if (!dot[i]) {
      dot[i] = 1;
      ip_addr_gen_inner (str, dot, num_dot + 1);
      dot[i] = 0;
    }
  }
}

void ip_addr_gen (char *str)
{
  int len = strlen (str);
  char *dot = (char *) calloc (len, sizeof (*dot));
  ip_addr_gen_inner (str, dot, 0);
}

void main ()
{
  //char str[] = "11211";
  char str[] = "25525511135";
  ip_addr_gen (str);
}
