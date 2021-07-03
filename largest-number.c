/*
https://leetcode.com/problems/largest-number/
*/
int cmp (const void *a, const void *b)
{
  int i, j;
  char *num1 = *((char **)a);
  char *num2 = *((char **)b);
  int num1_len = strlen (num1);
  int num2_len = strlen (num2);
  char ab[24] = {0};
  char ba[24] = {0};
  
  strcpy (ab, num1);
  strcpy (ab + num1_len, num2);
  
  strcpy (ba, num2);
  strcpy (ba + num2_len, num1);
  
  return -strcmp (ab, ba);
}

char * largestNumber(int* nums, int numsSize){
  int i, j, k, m;
  char **num_str = (char **) malloc (numsSize * sizeof (*num_str));
  
  for (i = 0; i < numsSize; i++) {
    num_str[i] = (char *) calloc (12, sizeof (char));
    sprintf (num_str[i], "%d", nums[i]);
  }
  qsort (num_str, numsSize, sizeof (char *), cmp);
  
  char *res = (char *) calloc (100 * 10000, sizeof (char));
  for (i = 0, k = 0; i < numsSize; i++) {
    for (j = 0; num_str[i][j]; j++) {
      res[k++] = num_str[i][j];
    }
  }
  while (res[0] == '0' && res[1] != '\0')
    res++;
  return res;
}
