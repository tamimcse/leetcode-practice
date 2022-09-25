/*
https://leetcode.com/problems/rearrange-spaces-between-words/
*/


char * reorderSpaces(char * text){
  int len = strlen (text), num_spaces = 0, num_word = 0;
  int i, j, k, num_spaces_bw, num_spaces_end;
  char *res = (char *) calloc (len + 1, sizeof (char));
  
  for (i = 0; i < len; i++) {
    if (text[i] == ' ') {
      num_spaces++;
    } else {
      if (i == 0 || text[i-1] == ' ')
        num_word++;
    }
  }
  
  if (num_word == 1) {
    num_spaces_end = num_spaces;
    num_spaces_bw = 0;
  } else {
    num_spaces_bw = num_spaces / (num_word - 1);
    num_spaces_end = num_spaces % (num_word - 1);
  }
  
  i = 0;
  j = 0;
  while (i < len) {
    while (j < len && text[j] == ' ')
      j++;
    if (j < len) {
      while (j < len && text[j] != ' ') {
        res[i++] = text[j++];
      }
      num_word--;
      if (num_word) {
        for (k = 0; k < num_spaces_bw; k++) {
          res[i++] = ' ';
        }  
      } else {
        for (k = 0; k < num_spaces_end; k++) {
          res[i++] = ' ';
        }
      }
      
    }
  }
  return res;
}
