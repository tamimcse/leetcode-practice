/*
https://leetcode.com/problems/boats-to-save-people/
*/
int cmp (const void *a, const void *b)
{
  return *((int *)a) - *((int *)b);
}

int numRescueBoats(int* people, int peopleSize, int limit){
  int start, end, count = 0;
    
  qsort (people, peopleSize, sizeof (int), cmp);
    
  for (start = 0, end = peopleSize - 1; end >= start; end--) {
    if (start < end && (people[end] + people[start]) <= limit) {
      start++;
    }
    count++;  
  }
  return count;  
}
