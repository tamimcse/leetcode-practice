/*
https://leetcode.com/problems/letter-combinations-of-a-phone-number/
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *arr[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void letterCombinations_inner(char * digits, int cur_idx, int last_idx, char *tmp_str, char **res, int *res_cnt){
  int i;
  char *cur_letters = arr[digits[cur_idx] - '0'];
  int len = strlen (cur_letters);
  char c;
  
  for (i = 0; i < len; i++) {
    tmp_str[cur_idx] = cur_letters[i];
    if (cur_idx == last_idx) {
      char *new_res = (char *) malloc ((last_idx + 2) * sizeof (*new_res));
      strcpy (new_res, tmp_str);
      res[*res_cnt] = new_res;
      (*res_cnt)++;
    } else {
      cur_idx++;
      letterCombinations_inner(digits, cur_idx, last_idx, tmp_str, res, res_cnt);  
      cur_idx--;
    }
  }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** letterCombinations(char *digits, int* returnSize){
  char **res = (char **) calloc (1600, sizeof (*res));
  int res_cnt = 0;
  int num_digits = strlen (digits);
  if (num_digits < 1) {
    *returnSize = 0;
    return res;
  }
    
  char *tmp_str = (char *) malloc ((num_digits + 1) * sizeof (*tmp_str));
  tmp_str[num_digits] = '\0';
  letterCombinations_inner (digits, 0, num_digits - 1, tmp_str, res, &res_cnt);
  *returnSize = res_cnt;
  return res;
}

void main ()
{
  char str[] = "";
  int ret_size;

  char **res = letterCombinations (str, &ret_size);
  for (int i = 0; i < ret_size; i++) {
    printf ("%s\n", res[i]);
  }

}
