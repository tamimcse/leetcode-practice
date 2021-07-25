/*
https://leetcode.com/problems/minimum-window-substring/

Very very very very very interesting problem. You will find discussion in notes
*/
void insert (int *hash, char ch)
{
  if (islower (ch)) {
    hash[ch - 'a'] += 1;
  } else {
    hash[26 + ch - 'A'] += 1;
  }  
}

int get_value (int *hash, char ch)
{
  if (islower (ch)) {
    return hash[ch - 'a'];
  } else {
    return hash[26 + ch - 'A'];
  }
}

void delete (int *hash, char ch)
{
  if (islower (ch)) {
    hash[ch - 'a'] -= 1;
  } else {
    hash[26 + ch - 'A'] -= 1;
  }
}

char * minWindow(char * s, char * t){
  int hash[52] = {0};
  int i, j, k, left, right;
  int t_len = strlen (t), s_len = strlen (s);
  int match_cnt;
  int min_window_len = strlen (s) + 1;
  int min_start = -1, min_end = -1;
  bool found;
  
  for (i = 0; t[i]; i++) {
    insert (hash, t[i]);
  }
  
  left = 0;
  while (left < s_len && !get_value (hash, s[left])) {
    left++;
  }
  right = left;
  
  if (left >= s_len)
    return "";
  
  match_cnt = 0;
  while (left <= s_len - t_len) {
    while (right < s_len && match_cnt < t_len) {
      if (get_value (hash, s[right]) > 0)
        match_cnt++;
      delete (hash, s[right]);
      right++;
    }
    if (match_cnt < t_len)
      break;
    while (get_value (hash, s[left]) < 0) {
      insert (hash, s[left]);
      left++;      
    }
    if (right - left < min_window_len) {
      min_window_len = right - left;
      min_start = left;
      min_end = right - 1;
    }
    insert (hash, s[left]);
    left++;
    match_cnt--;
  }

  if (min_start == -1) {
    return "";
  }
  
  int res_len = min_end - min_start + 1;
  char *res = (char *) malloc ((res_len + 1) * sizeof (char));
  res[res_len] = '\0';
  memcpy (res, s + min_start, res_len * sizeof (char));
  return res;
}
