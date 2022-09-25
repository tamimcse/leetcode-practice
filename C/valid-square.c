/*
https://leetcode.com/problems/valid-square/
*/
int distance (int* p1, int* p2)
{
  return pow (p2[0] - p1[0], 2) + pow (p2[1] - p1[1], 2);
}

bool valid (int* p1, int* p2, int *p3, int *p4, int *ret_size, int *ret_diag)
{
  int size, diag, dis1, dis2, dis3;
  
  dis1 = distance (p1, p2);
  dis2 = distance (p1, p3);
  dis3 = distance (p1, p4);
  
  if (dis1 != dis2 && dis2 != dis3 && dis3 != dis1)
    return false;
  if (dis1 == dis2) {
    size = dis1;
    diag = dis3;
  } else if (dis2 == dis3) {
    size = dis2;
    diag = dis1;
  } else {
    size = dis3;
    diag = dis2;
  }
    
  if (2 * size != diag)
    return false;
  
  *ret_size = size;
  *ret_diag = diag;
  return true;
}

bool validSquare(int* p1, int p1Size, int* p2, int p2Size, int* p3, int p3Size, int* p4, int p4Size){
  int size, diag, dis1, dis2, dis3, ret_size, ret_diag;
  bool res;
  
  dis1 = distance (p1, p2);
  dis2 = distance (p1, p3);
  dis3 = distance (p1, p4);
  
  if (dis1 != dis2 && dis2 != dis3 && dis3 != dis1)
    return false;

  if (dis1 == dis2) {
    size = dis1;
    diag = dis3;
  } else if (dis2 == dis3) {
    size = dis2;
    diag = dis1;
  } else {
    size = dis3;
    diag = dis2;
  }
 
  if (2 * size != diag)
    return false;
  
  if (!size)
    return false;
  
  res = valid (p2, p1, p3, p4, &ret_size, &ret_diag);
  if (!res || ret_size != size || ret_diag != diag)
    return false;
  
  res = valid (p3, p1, p2, p4, &ret_size, &ret_diag);
  if (!res || ret_size != size || ret_diag != diag)
    return false;
  
  res = valid (p4, p1, p2, p3, &ret_size, &ret_diag);
  if (!res || ret_size != size || ret_diag != diag)
    return false;
  return true;
}
