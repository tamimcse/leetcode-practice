/*
https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

I was asked at Juniper.
*/

char * removeDuplicates(char * s, int k){
  int i, j, len = strlen (s), idx;  
  char *stack = (char *) malloc (len * sizeof (char));
  int *count = (int *) malloc (len * sizeof (int));
  char *res = (char *) calloc (len + 1, sizeof (char));
   
  stack[0] = s[0];
  count[0] = 1;
  idx = 1;  
  for (i = 1; s[i]; i++) {
    if (idx >= 1 && s[i] == stack[idx - 1]) {
      count[idx - 1]++;
      if (idx >= 1 && count[idx - 1] == k) {
          idx--;
      }
    } else {
      stack[idx] = s[i];
      count[idx] = 1;
      idx++;
    }
  }
  
  for (i = 0, j = 0; i < idx; i++) {
    while (count[i]) {
      res[j++] = stack[i];  
      count[i]--;
    }  
  }
  return res;
}
