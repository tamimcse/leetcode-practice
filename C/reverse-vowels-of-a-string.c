/*
https://leetcode.com/problems/reverse-vowels-of-a-string/
*/
bool is_vowel (char c)
{
  c = tolower (c);
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

char * reverseVowels(char * s){
  int start = 0, len = strlen (s), end = len - 1;
  char tmp;
  
  while (end > start) {
    while (start < len && !is_vowel (s[start]))
      start++;
    while (end >= 0 && !is_vowel (s[end]))
      end--;
    if (end > start) {
      tmp = s[start];
      s[start] = s[end];
      s[end] = tmp;
      start++;
      end--;
    }
  }
  return s;
}
