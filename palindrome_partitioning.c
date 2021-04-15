/*
https://www.geeksforgeeks.org/palindrome-partitioning-dp-17/

Not finished
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_palindrome (char *str, int start, int end)
{
  while (end >= start ) {
    if (str[start] != str[end])
      return false;
    start++;
    end--;
  }
  return true;
}

int palindrome_partition (char *str)
{

}

void main ()
{
  char str[] = "ababb";

}
