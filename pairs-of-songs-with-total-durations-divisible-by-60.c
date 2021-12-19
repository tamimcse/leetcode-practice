/*
https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
*/
int cmp (const void *a, const void *b)
{
  return *((int *)a) - *((int *)b);    
}

int numPairsDivisibleBy60(int* time, int timeSize){
  int i, j, start, end, count = 0, to_find, start1, end1, mid1;
    
  for (i = 0; i < timeSize; i++) {
    time[i] = time[i] % 60;  
  }
    
  qsort (time, timeSize, sizeof (int), cmp);
    
  start = 0;
  while (start < timeSize && !time[start])
    start++;
  if (start > 1) {
    count = ((start - 1) * start) >> 1;
  }
  for (; start < timeSize - 1; start++) {
    to_find = 60 - time[start];
    if (to_find < time[start])
      break;  
    start1 = start + 1;
    end1 = timeSize - 1;  
    while (start1 <= end1) {
      mid1 = (start1 + end1) >> 1;
      if (time[mid1] == to_find) {
        while (mid1 - 1 >= start1 && time[mid1 - 1] == time[mid1]) {
          mid1--;  
        } 
        count++;
        while (mid1 + 1 <= end1 && time[mid1 + 1] == time[mid1]) {
          mid1++;
          count++;
        }
        break;
      } else if (to_find > time[mid1]) {
        start1 = mid1 + 1;
      } else {
        end1 = mid1 - 1;
      } 
    }  
  }
  return count;  
}

/*
Better approach!!

int cmp (const void *a, const void *b)
{
  return *((int *)a) - *((int *)b);    
}

int numPairsDivisibleBy60(int* time, int timeSize){
  int i, j, start, end, count = 0, to_find, start1, end1, mid1, len;
  int *arr;
    
  for (i = 0; i < timeSize; i++) {
    time[i] = time[i] % 60;  
  }
    
  int freq[60] = {0};  
  
  for (i = 0; i < timeSize; i++) {
    freq[time[i]]++;  
  }
  
  len = 0;
  for (i = 1; i < 60; i++) {
    if (freq[i])
      len++;  
  }
  
  arr = (int *) malloc (len * sizeof (int));
  for (i = 1, j = 0; i < 60; i++) {
    if (freq[i]) {
      arr[j++] = i;  
    }
  }
    
  count = (freq[0] * (freq[0] - 1)) >> 1;
    
  count += ((freq[30] * (freq[30] - 1)) >> 1);  
    
  for (start = 0; start < len - 1; start++) {
    to_find = 60 - arr[start];
    if (to_find < arr[start])
      break;  
    start1 = start + 1;
    end1 = len - 1;
    while (start1 <= end1) {
      mid1 = (start1 + end1) >> 1;
      if (arr[mid1] == to_find) {
        count += freq[to_find] * freq[arr[start]];
        break;
      } else if (to_find > arr[mid1]) {
        start1 = mid1 + 1;
      } else {
        end1 = mid1 - 1;
      } 
    }  
  }
  return count;  
}
*/
