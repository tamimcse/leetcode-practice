/*
https://leetcode.com/problems/flip-game/
*/


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** generatePossibleNextMoves(char * currentState, int* returnSize){
  int i, j, len = strlen (currentState);
  char **res = (char **) malloc (len * 100 * sizeof (*res));
  int res_cnt = 0;
  char *new_res;
  
  for (i = 0; i < len - 1; i++) {
    if (currentState[i] == '+' && currentState[i+1] == '+' ) {
      new_res = (char *) malloc ((len + 1) * sizeof (char));
      strcpy (new_res, currentState);
      new_res[i] = '-';
      new_res[i+1] = '-';
      res[res_cnt++] = new_res;
    }
  }
  *returnSize = res_cnt;
  return res;
}
