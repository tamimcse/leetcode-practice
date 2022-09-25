/*
https://sites.google.com/site/yunrockqu/blog/interview-questions-1?authuser=0

Cisco question.

Given a single-bit streaming input, how do we report (mod 5) results of the stream? An example is shown in the following table: 

Input:   1 0 1 1
Output:  1 2 0 1 
*/
#include <stdio.h>

int num = 0;

void insert (int a)
{
  num = (num << 1) | a;
  printf ("%d ", num % 5);
}

void main ()
{
  int arr[] = {1, 0, 1, 1, 1};
  int len = sizeof (arr) / sizeof (arr[0]);

  for (int i = 0; i < len; i++) {
    insert (arr[i]);
  }
  printf ("\n");
}




