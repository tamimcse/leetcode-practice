/*
https://leetcode.com/problems/sum-of-two-integers/

Look at the solution in leetcode if needed.
*/
int add (int a, int b)
{
  int xor, carry;
  do {
    xor = a ^ b;
    carry = (a & b) << 1;
    a = xor;
    b = carry;
  } while (carry);
  return a;
}

int sub (int a, int b)
{
  int xor, borrow;
  
  do {
    xor = a ^ b;
    borrow = ((~a) & b) << 1;
    a = xor;
    b = borrow;
  } while (borrow);
  return a;
}

int getSum(int a, int b){
  if (a >= 0 && b >= 0) {
    return add (a, b);
  } else if (a < 0 && b < 0) {
    return -add (abs(a), abs (b));
  } else if (a < 0) {
    if (b >= abs (a))
      return sub (b, abs(a));
    else 
      return -sub (a, b);
  } else {
    if (a >= abs (b))
      return sub (a, b);
    else
      return - sub (abs (b), a); 
  }
}
