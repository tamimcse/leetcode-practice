/*
https://leetcode.com/problems/course-schedule-ii/
*/


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize){
  int *res = (int *) malloc (numCourses * sizeof (int));
  int res_cnt = numCourses;
  int i, j, k;
  int *indegrees = (int *) calloc (numCourses, sizeof (int));
  int *visit = (int *) calloc (numCourses, sizeof (int));
  int *stack = (int *) malloc (numCourses * 2 * sizeof (int));
  int start = -1, s_idx = 0, cur;
  
  for (i = 0; i < prerequisitesSize; i++) {
    indegrees[prerequisites[i][0]]++;
  } 

  for (j = 0; j < numCourses; j++) {
    if (visit[j])
      continue;
    start = j;
    s_idx = 0;
    stack[s_idx++] = start;
    while (s_idx) {
      cur = stack[s_idx - 1];
      if (visit[cur] == 2) {
        s_idx--;
        continue;
      }
      if (visit[cur] == 1) {
        visit[cur] = 2;
        res[--res_cnt] = cur;
        s_idx--;
        continue;
      }
      visit[cur] = 1;
      for (i = 0; i < prerequisitesSize; i++) {
        if (prerequisites[i][1] == cur) {
          if (visit[prerequisites[i][0]] == 1) {
            *returnSize = 0;
            return res;
          }
          stack[s_idx++] = prerequisites[i][0];
        }
      }
    }
  }
  if (start == -1) {
    *returnSize = 0;
    return res;
  }
    
  *returnSize = numCourses;
  return res;
}
