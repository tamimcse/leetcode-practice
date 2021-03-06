/*
Implement sizeof (var)
*/
#include <stdio.h>

#define var_sizeof(x) (char *)((&x) + 1) - (char *)(&x)

void main ()
{
  int size;
  double d;
  
  size = var_sizeof (d);
  printf ("Sizeof the variable is %d\n", size);
  
}
