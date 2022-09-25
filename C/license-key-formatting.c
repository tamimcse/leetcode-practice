/*
https://leetcode.com/problems/license-key-formatting/
*/

char * licenseKeyFormatting(char * s, int k){
  int i, j, m, num_chars = 0, num_groups, num_elem_first;
  
  for (i = 0; s[i]; i++) {
    if (s[i] == '-')
      continue;
    num_chars++;
    if (isalpha(s[i]))
      s[i] = toupper (s[i]);
  }
  
  if (!num_chars)
    return "";
  
  if (num_chars % k == 0) {
    num_groups = num_chars / k;
    num_elem_first = k;
  } else {
    num_groups = num_chars / k + 1;
    num_elem_first = num_chars % k;
  }
  
  char *res = (char *) malloc ((num_chars + num_groups) * sizeof (char));
  res[num_chars + num_groups - 1] = '\0';
  
  for (i = 0, j = 0, m = 0; s[i]; i++) {
    if (s[i] == '-')
      continue;
    res[j++] = s[i];
    m++;
    if (j == num_elem_first || k == m) {
      res[j++] = '-';
      m = 0;
    }
  }
  res[j-1] = '\0';
  return res;
}
