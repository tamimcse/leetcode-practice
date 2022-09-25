/*
https://leetcode.com/problems/plus-one/
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
  int carry = 1, i = digitsSize - 1;
  int *res;
  while (i >= 0 && carry) {
    if (digits[i] == 9) {
      digits[i] = 0;
      carry = 1;
    } else {
      digits[i] += 1;
      carry = 0;
    }
    i--;
  }
  
  if (carry) {
    res = (int *) malloc ((digitsSize + 1) * sizeof (int));
    *returnSize = digitsSize + 1;
    res[0] = 1;
    memcpy (res + 1, digits, digitsSize * sizeof (int));
    return res;
  } else {
    *returnSize = digitsSize;
    return digits;
  }
}
