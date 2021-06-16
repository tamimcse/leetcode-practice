/*
https://leetcode.com/problems/all-paths-from-source-to-target/

Implemented using DFS + Backtracking
*/


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** allPathsSourceTarget(int** graph, int graphSize, int* graphColSize, int* returnSize, int** returnColumnSizes){
  int stack[100];
  int s_idx = 0;
  int **res = (int **) malloc (200 * graphSize * graphSize * sizeof (*res));
  int res_cnt = 0;
  int *visit = (int *) calloc (graphSize, sizeof (*visit));
  int *path = (int *) calloc (graphSize, sizeof (*path));
  int path_cnt = 0;
  int src = 0, target = graphSize - 1, curr, i, j, adj;
  *returnColumnSizes = (int *) malloc (200 * graphSize * graphSize * sizeof (int));
  
  stack[s_idx++] = src;
  while (s_idx) {
    curr = stack[s_idx-1];
    if (curr == target) {
      res[res_cnt] = (int *) malloc ((path_cnt + 1) * sizeof (int));
      memcpy (res[res_cnt], path, (path_cnt + 1) * sizeof (int));
      res[res_cnt][path_cnt] = target;
      (*returnColumnSizes)[res_cnt] = path_cnt + 1;
      res_cnt++;
      s_idx--;
      continue;
    }
    if (visit[curr]) {
      s_idx--;
      path_cnt--;
      //backtracking algorithm
      visit[curr] = 0;
      continue;
    }
    visit[curr] = 1;
    path[path_cnt++] = curr;
    for (i = 0; i < graphColSize[curr]; i++) {
      adj = graph[curr][i];
      if (visit[adj])
        continue;
      stack[s_idx++] = adj;
    }
  }
  *returnSize = res_cnt;
  return res;
}
