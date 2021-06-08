/*
https://leetcode.com/problems/string-compression/
*/
int compress(char* chars, int charsSize){
  int i, count = 1, to_idx = 1;
  bool seen = false;
  int last_num_idx = -1;
  
  for (i = 1; i < charsSize; i++) {
    if (chars[i] == chars[i-1]) {
      count++;
    } else {
      if (count == 1) {
        chars[to_idx++] = chars[i];  
      } else {
        if (count < 10) {
          chars[to_idx++] = count + '0';
        } else {
          chars[to_idx++] = count/10 + '0';
          chars[to_idx++] = count%10 + '0';
        }
        chars[to_idx++] = chars[i];
        count = 1;
      }
    }
  }
  if (count > 1) {
    if (count < 10) {
      chars[to_idx++] = count + '0';
    } else {
      chars[to_idx++] = count/10 + '0';
      chars[to_idx++] = count%10 + '0';
    }
  }
  return to_idx;
}
