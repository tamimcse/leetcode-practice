/*
https://leetcode.com/problems/h-index/
*/
int cmp (const void *a, const void *b)
{
  return *((int *)a) - *((int *)b);
}

int hIndex(int* citations, int citationsSize){
  int i, j, k;
  
  qsort (citations, citationsSize, sizeof (int), cmp);
  
  for (i = citationsSize - 1; i >= 0; i--) {
    if (!citations[i])
      break;
    while (i >= 1 && citations[i] == citations[i-1]) {
      i--;
    }
    k = i >= 1 ? citations[i-1] + 1 : 0;
    for (j = citations[i]; j >= k; j--) {
      if (j <= citationsSize - i)
        return j;
    }
  }
  
  for (i = 0; i < citationsSize; i++) {
    if (citations[i])
      return citationsSize - i;
  }
    
  return 0;
}
