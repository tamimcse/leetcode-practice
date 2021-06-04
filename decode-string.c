/*
https://leetcode.com/problems/decode-string/
*/
char * decodeString(char * s){
  int *stack1 = (int *) malloc (30 * sizeof (int));
  int *stack2 = (int *) malloc (30 * sizeof (int));
  int stack_idx = 0;
  char *new_str;
  bool digit_found = false;
  int start, end, len = strlen (s);
  int i, j, k, sum, num, str_start;
  
  for (i = 0; s[i]; i++) {
    if (s[i] == '[') {
      end = i - 1;
      for (j = i - 1; j >= 0 && isdigit(s[j]); j--);
      start = j + 1;
      sum = 0;
      for (j = start; j <= end; j++) {
        sum = sum * 10 + (s[j] - '0');
      }
      stack1[stack_idx] = sum;
      stack2[stack_idx] = start;
      stack_idx++;
    }
    
    if (s[i] == ']') {
      stack_idx--;
      num = stack1[stack_idx];
      start = stack2[stack_idx];
      end = i;
      for (j = i - 1; j >= 0 && s[j] != '['; j--);
      str_start = j + 1;
      int new_str_len = (end - str_start) * num;
      int str_to_replace_len = end - start + 1;
      int new_len = strlen(s) + 1 - str_to_replace_len + new_str_len;
      new_str = (char *) malloc (new_len * sizeof (char));
      new_str[new_len - 1] = '\0';
      memcpy (new_str, s, sizeof (char) * start);
      for (j = 0, k = start; j < num; j++, k += (end - str_start)) {
        memcpy (new_str + k, &s[str_start], sizeof (char) * (end - str_start));
      }
      if (s[end + 1] != '\0')
        memcpy (new_str + k, &s[end + 1], sizeof (char) * (strlen(s) - 1 - end));
      free(s);
      s = new_str;
      i = k - 1;
    }
  }
  return s;
}
