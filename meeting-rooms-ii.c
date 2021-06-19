/*
https://leetcode.com/problems/meeting-rooms-ii/

https://www.geeksforgeeks.org/minimum-halls-required-for-class-scheduling/

very interesting problem!!

Note that, this problem may look like backtracking. In this problem, I also tried to think if greedy approach works. Then I found in geeksforgeeks that the number of rooms required is the maximum number of meetings happening at the same time. Then I was thinking about an algorithm to calculate that. I came up with this: sort the intervals based on start time. Then for each interval increase the count when you find an overlapping interval. We do that until we find a meeting where start time is larger than the end time of the current meeting. This approach should work. But, we can improve the algorithm using extra space. We allocate an array and project each interval in the array as described in geeksfor geeks.  
*/
int minMeetingRooms(int** intervals, int intervalsSize, int* intervalsColSize){
  int i, end, max;
  
  end = intervals[0][1];
  for (i = 1; i < intervalsSize; i++) {
    if (intervals[i][1] > end)
      end = intervals[i][1];
  }
  
  int *counts_per_time = (int *) calloc (end + 2, sizeof (int));
  for (i = 0; i < intervalsSize; i++) {
    counts_per_time[intervals[i][0]]++;
    counts_per_time[intervals[i][1]]--;
  }
  
  for (i = 1; i < end + 2; i++) {
    counts_per_time[i] = counts_per_time[i] + counts_per_time[i-1];
  }
  
  max = counts_per_time[0];
  for (i = 1; i < end + 2; i++) {
    if (counts_per_time[i] > max)
      max = counts_per_time[i];
  }
  return max;
}
