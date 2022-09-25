/*
https://www.geeksforgeeks.org/remove-spaces-from-a-given-string/
*/
#include <stdio.h>

void in_place_space_removal (char *str)
{
  int i;
  int count = 0;//keep track of the non-space characters

  for (i = 0; i < str[i]; i++) {
    if (str[i] != ' ') {
      str[count++] = str[i];
    }
  }
  str[count] = '\0';
}

void main ()
{
  //This cannot be modified. Use char [] instead
  //char *str = "Cisco is hiring";

  char str[] = "Cisco is hiring";
  in_place_space_removal (str);
  printf ("Result = %s \n", str);
}
