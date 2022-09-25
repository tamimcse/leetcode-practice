/*
https://leetcode.com/problems/compare-version-numbers/
*/
int compareVersion(char * version1, char * version2){
  int revision1, revision2;
  
  while (*version1 || *version2) {
    revision1 = 0;
    revision2 = 0;
    if (*version1) {
      while (*version1 && *version1 != '.') {
        revision1 = revision1 * 10 + (*version1 - '0');
        version1++;
      }
      if (*version1 == '.')
        version1++;
    }
    if (*version2) {
      while (*version2 && *version2 != '.') {
        revision2 = revision2 * 10 + (*version2 - '0');
        version2++;
      }
      if (*version2 == '.')
        version2++;
    }
    if (revision1 != revision2) {
      return revision1 - revision2 > 0 ? 1 : -1;
    }
  }
  return 0;
}
