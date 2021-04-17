/*
https://www.geeksforgeeks.org/total-area-two-overlapping-rectangles/
*/
#include <stdio.h>

#define MAX(X,Y) X > Y ? X : Y
#define MIN(X,Y) X < Y ? X : Y

int area (int x1, int y1, int x2, int y2)
{
  if (x1 >= x2 || y1 >= y2)
    return 0;
  return (x2 - x1) * (y2 - y1);

}

void overlapping_area (int blx1, int bly1, int trx1, int try1, int blx2, int bly2, int trx2, int try2)
{
  //overlapping rectaangle
  int x1, y1, x2, y2;

  x1 = MAX (blx1, blx2);
  y1 = MAX (bly1, bly2);
  x2 = MIN (trx1, trx2);
  y2 = MIN (try1, try2);

  int res = area (x1, y1, x2, y2);
  printf ("Overhapping area is %d \n", res);
}

void main ()
{
  int blx1 = 1, bly1 = 2, trx1 = 8, try1 = 5, blx2 = 2, bly2 = 1, trx2 = 10, try2 = 7;

  overlapping_area (blx1, bly1, trx1, try1, blx2, bly2, trx2, try2);
}
