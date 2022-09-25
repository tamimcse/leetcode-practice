/*
https://leetcode.com/problems/course-schedule/
*/

struct edge {
  int v2;
  struct edge *next;
};

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize){
  struct edge **adj_list = (struct edge **) calloc (numCourses, sizeof (*adj_list));
  int i, j, curr;
  struct edge *new_edge;
  int *in_degrees = (int *) calloc (numCourses, sizeof (*in_degrees));
  int *visit = (int *) calloc (numCourses, sizeof (*visit));
  int *stack = (int *) malloc (numCourses * 2 * sizeof (*stack));
  int s_idx;
  struct edge *runner;
  //bool found_first = false; 
  
  for (i = 0; i < prerequisitesSize; i++) {
    new_edge = (struct edge *) malloc (sizeof (*new_edge));
    new_edge->v2 = prerequisites[i][1];
    new_edge->next = adj_list[prerequisites[i][0]];
    adj_list[prerequisites[i][0]] = new_edge;
  }
  
  for (i = 0; i < prerequisitesSize; i++) {
    in_degrees[prerequisites[i][1]]++;
  }
  
  for (i = 0; i < numCourses; i++) {
    if (visit[i] == 2)
      continue;
    //found_first = true;
    s_idx = 0;
    stack[s_idx++] = i;
    while (s_idx) {
      curr = stack[s_idx - 1];
      if (visit[curr] == 1) {
        s_idx--;
        visit[curr] = 2;
        continue;
      }
      visit[curr] = 1;
      runner = adj_list[curr];
      while (runner) {
        if (visit[runner->v2] == 1)
          return false;
        //not already visited
        if (visit[runner->v2] != 2)
          stack[s_idx++] = runner->v2;
        runner = runner->next;
      }
    }
  }
  return true;
}
