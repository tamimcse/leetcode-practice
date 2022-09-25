/*
https://leetcode.com/problems/longest-repeating-character-replacement/
*/

int characterReplacement(char * s, int k){
  int hash[26] = {0};
  int left = 0, right = 0, len = strlen (s), i, j, max_len, max_window_len = 0;
  
  hash[s[0]- 'A']++;
  while (left < len && right < len) {
    max_len = hash[s[left] - 'A'];
    for (i = left + 1; i <= right; i++) {
      if (hash[s[i] - 'A'] > max_len)
        max_len = hash[s[i] - 'A'];
    }
    if (right - left + 1 - max_len <= k) {
      if (right - left + 1 > max_window_len)
        max_window_len = right - left + 1;
      right++;
      if (right < len)
        hash[s[right] - 'A']++;
    } else {
      hash[s[left] - 'A']--;
      left++;
    }
  }
  return max_window_len;
}
