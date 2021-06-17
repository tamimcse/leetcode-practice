/*
https://leetcode.com/problems/interval-list-intersections/
*/
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** intervalIntersection(int** firstList, int firstListSize, int* firstListColSize, int** secondList, int secondListSize, int* secondListColSize, int* returnSize, int** returnColumnSizes){
  int res_max = firstListSize + secondListSize;
  int **res = (int **) malloc (res_max * sizeof (*res));
  int res_cnt = 0;
  *returnColumnSizes = (int *) malloc (res_max * sizeof (int));
  int i, j, k, start, end;
  for (i = 0; i < res_max; i++)
    (*returnColumnSizes)[i] = 2;
  
  i = 0;
  j = 0;
  while (i < firstListSize && j < secondListSize) {
    if (secondList[j][0] > firstList[i][1]) {
      i++;
      continue;
    }
    if (firstList[i][0] > secondList[j][1]) {
      j++;
      continue;
    }
    start = secondList[j][0] >= firstList[i][0] ? secondList[j][0] : firstList[i][0];
    end = secondList[j][1] <= firstList[i][1] ? secondList[j][1] : firstList[i][1];
    res[res_cnt] = (int *) malloc (2 * sizeof (int));
    res[res_cnt][0] = start;
    res[res_cnt][1] = end;
    res_cnt++;
    if (secondList[j][1] == firstList[i][1]) {
      i++;
      j++;
    } else if (secondList[j][1] < firstList[i][1]) {
      j++;
    } else {
      i++;
    }
  }
  *returnSize = res_cnt;
  return res;
}
