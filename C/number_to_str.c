/*
Returning the word form of any number, e.g: 231: Two hundred thirty one. The code need to support upto 4 digits.
*/
#include <stdio.h>

void number_to_str (int a, char *str)
{
  char *map_ones[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  char *map_tens[] = {"", "", "twinty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
  char *map_elevens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

  int thousands = a / 1000;
  int hundreds = (a % 1000) / 100;
  int tens = (a % 100) / 10;
  int ones = a % 10;
  
  char two_digits[100];
  if (tens == 1) {
    sprintf (two_digits, "%s", map_elevens[ones]);
  } else {
    sprintf (two_digits, "%s %s", map_tens[tens], ones ? map_ones[ones] : "");
  }

  sprintf (str, "%s %s %s %s %s", 
           thousands ? map_ones[thousands]: "", thousands ? "thousand" : "",
           hundreds ? map_ones[hundreds] : "", hundreds ? "hundred" : "",
           two_digits);
}

void main ()
{
  char str[200];
  number_to_str (2345, str);
  printf ("%s\n", str);
} 
