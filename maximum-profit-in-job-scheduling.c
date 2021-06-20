/*
https://leetcode.com/problems/maximum-profit-in-job-scheduling/

https://www.geeksforgeeks.org/weighted-job-scheduling/

See note that the end....
*/
struct job {
  int start_time;
  int end_time;
  int profit;
};

int cmp (const void *a, const void *b)
{
  return ((struct job *)a)->end_time - ((struct job *)b)->end_time;
}

int jobScheduling(int* startTime, int startTimeSize, int* endTime, int endTimeSize, int* profit, int profitSize){
  int i, j, k, tot_profit;
  struct job *jobs = (struct job *) malloc (startTimeSize * sizeof (*jobs));
  int *dp = (int *) calloc (startTimeSize, sizeof (*dp));
  
  for (i = 0; i < startTimeSize; i++) {
    jobs[i].start_time = startTime[i];
    jobs[i].end_time = endTime[i];
    jobs[i].profit = profit[i];
  }
  
  qsort (jobs, startTimeSize, sizeof (*jobs), cmp);
  
  dp[0] = jobs[0].profit;
  for (i = 1; i < startTimeSize; i++) {
    tot_profit = jobs[i].profit;
    for (j = i - 1; j >= 0; j--) {
      if (jobs[j].end_time <= jobs[i].start_time) {
        tot_profit += dp[j];
        break;
      }
    }    
    dp[i] = dp[i-1] > tot_profit ? dp[i-1] : tot_profit;
  }
  return dp[startTimeSize-1];
}
/*
Follow the recursive solution of geeksforgeeks. Then implement DP.
*/
