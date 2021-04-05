/*
https://www.geeksforgeeks.org/check-if-a-queen-can-attack-a-given-cell-on-chessboard/
*/
#include <stdio.h>
#include <stdbool.h>

bool queen_attack (int qX, int qY, int oX, int oY)
{
  return qX == oX || qY == oY || (qX - oX) == (qY - oY);
}

void main ()
{
  int qX = 4, qY = 5, oX = 6, oY = 7;
//  int qX = 1, qY = 1, oX = 3, oY = 2;

  bool res = queen_attack (qX, qY, oX, oY);
  printf ("The %s attck\n", res ? "can" : "cannot");
      
}
