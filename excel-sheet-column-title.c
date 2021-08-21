/*
https://leetcode.com/problems/excel-sheet-column-title/

Very very interesting problem!
*/


char * convertToTitle(int columnNumber){
  int num_digit = log10 (columnNumber) / log10 (26) + 1;
  char *res = (char *) calloc (num_digit + 1, sizeof (char));
  int i, j, rem;
  char tmp;
  
  i = num_digit - 1;
  while (columnNumber > 26) {
    rem = columnNumber % 26;
    columnNumber /= 26;
    if (!rem) {
      rem = 26;
      columnNumber--;
    }
    res[i--] = (rem % 27) - 1 + 'A';
  }
  
  if (columnNumber) {
    res[i--] = (columnNumber % 27) + ('A' - 1);
  }
  
  
  return &res[i+1];
}
