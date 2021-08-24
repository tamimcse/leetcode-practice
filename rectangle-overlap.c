/*
https://leetcode.com/problems/rectangle-overlap/
*/
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
  int x1 = rec1[0], y1 = rec1[1], x2 = rec1[2], y2 = rec1[3];
  int x3 = rec2[0], y3 = rec2[1], x4 = rec2[2], y4 = rec2[3];
  
  return !(x3 >= x2 || x4 <= x1 || y3 >= y2 || y4 <= y1);
}
