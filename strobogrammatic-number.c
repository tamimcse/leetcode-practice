/*
https://leetcode.com/problems/strobogrammatic-number/
*/
bool isStrobogrammatic(char * num){
  int len = strlen (num);
  char *upside_down = (char *) malloc ((len + 1) * sizeof (char));
  upside_down[len] = '\0';
  int curr;
  int i;
  
  for (i = 0; num[i]; i++) {
    curr = num[i] - '0';
    if ((curr >= 2 && curr <= 5) || curr == 7) {
      return false;
    }
    switch (curr) {
      case 0:
      case 8:
      case 1:
        upside_down[len - 1 - i] = num[i];
        break;
      case 6:
        upside_down[len - 1 - i] = '9';
        break;
      case 9:
        upside_down[len - 1 - i] = '6';
        break;
    }
  }
  
  return strcmp (num, upside_down) == 0;
}
