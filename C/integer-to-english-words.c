/*
https://leetcode.com/problems/integer-to-english-words/
*/
char* two_digit_num_to_str (int a)
{
  switch (a) {
    case 0:
      return "Zero";
    case 10:
      return "Ten";
    case 11:
      return "Eleven";
    case 12:
      return "Twelve";
    case 13:
      return "Thirteen";
    case 14:
      return "Fourteen";
    case 15:
      return "Fifteen";
    case 16:
      return "Sixteen";
    case 17:
      return "Seventeen";
    case 18:
      return "Eighteen";
    case 19:
      return "Nineteen";
  }
  
  char *one_str = "", *ten_str = ""; 
  int ten = a / 10, one = a % 10;
  char *out = (char *) calloc (100, sizeof (char));
  
  switch (ten) {
    case 0:
      ten_str = "";
      break;
    case 2:
      ten_str = "Twenty";
      break;
    case 3:
      ten_str = "Thirty";
      break;
    case 4:
      ten_str = "Forty";
      break;
    case 5:
      ten_str = "Fifty";
      break;
    case 6:
      ten_str = "Sixty";
      break;
    case 7:
      ten_str = "Seventy";
      break;
    case 8:
      ten_str = "Eighty";
      break;
    case 9:
      ten_str = "Ninety";
      break;
  }
  
  switch (one) {
    case 0:
      one_str = "";
      break;
    case 1:
      one_str = "One";
      break;
    case 2:
      one_str = "Two";
      break;
    case 3:
      one_str = "Three";
      break;
    case 4:
      one_str = "Four";
      break;
    case 5:
      one_str = "Five";
      break;
    case 6:
      one_str = "Six";
      break;
    case 7:
      one_str = "Seven";
      break;
    case 8:
      one_str = "Eight";
      break;
    case 9:
      one_str = "Nine";
      break;
  }
  if (ten) {
    sprintf (out, "%s", ten_str);
    if (one) {
      sprintf (out, "%s %s", out, one_str);
    }
  } else {
    sprintf (out, "%s", one_str);
  }
  return out;
}

char* three_digit_num_to_str (int a)
{
  int hundred = a / 100;
  int two_digit = a % 100;
  char *hundred_str = two_digit_num_to_str (hundred);
  char *two_digit_str = two_digit_num_to_str (two_digit);
  char *out = (char *) calloc (100, sizeof (char));
  
  if (hundred) {
    sprintf (out, "%s Hundred", hundred_str);
    if (two_digit) {
      sprintf (out, "%s %s", out, two_digit_str);
    }
  } else {
    sprintf (out, "%s", two_digit_str);
  }
  return out;
}

char * numberToWords(int num){
  char *out = (char *) calloc (1000, sizeof (char));
  int curr;
  bool empty = true;
  
  if (num == 0)
    return "Zero";

  if (num >= 1000000000) {
    curr = num /1000000000;
    num = num % 1000000000;
    sprintf (out, "%s%s Billion", empty ? "" : " ", three_digit_num_to_str (curr));
    empty = false;    
  }
  if (num >= 1000000) {
    curr = num /1000000;
    num = num % 1000000;
    sprintf (out, "%s%s%s Million", out, empty ? "" : " ", three_digit_num_to_str (curr));
    empty = false;    
  }
  if (num >= 1000) {
    printf ("here %s %d \n", out, num);
    curr = num /1000;
    num = num % 1000;
    sprintf (out, "%s%s%s Thousand", out, empty ? "" : " ", three_digit_num_to_str (curr));
    empty = false;
  }

  if (num) {
    sprintf (out, "%s%s%s", out, empty ? "" : " ", three_digit_num_to_str (num));
  }
  return out;
}
