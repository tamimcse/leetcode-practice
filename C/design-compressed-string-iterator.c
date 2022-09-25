/*
https://leetcode.com/problems/design-compressed-string-iterator/
*/



typedef struct {
    char *str;
    int cur_char_cnt;
    int num_digit;
} StringIterator;


StringIterator* stringIteratorCreate(char * compressedString) {
  StringIterator *s = (StringIterator *) malloc (sizeof (*s));
  s->str = compressedString;
  s->cur_char_cnt = -1;
  return s;
}

char stringIteratorNext(StringIterator* obj) {
  int sum = 0, i;
  char tmp;
  
  if (*(obj->str) == '\0')
    return ' ';
  tmp = obj->str[0];
  if (obj->cur_char_cnt == -1) {
    i = 1;
    while (isdigit (obj->str[i])) {
      sum = sum * 10 + (obj->str[i++] - '0');
    }
    obj->cur_char_cnt = sum;
    obj->num_digit = i - 1;
  }
  
  if (obj->cur_char_cnt > 1) {
    obj->cur_char_cnt--;
  } else {
    obj->str = obj->str + 1 + obj->num_digit;
    obj->cur_char_cnt = -1;
  }
  return tmp;
}

bool stringIteratorHasNext(StringIterator* obj) {
  return *(obj->str) != '\0';
}

void stringIteratorFree(StringIterator* obj) {
    free (obj);
}

/**
 * Your StringIterator struct will be instantiated and called as such:
 * StringIterator* obj = stringIteratorCreate(compressedString);
 * char param_1 = stringIteratorNext(obj);
 
 * bool param_2 = stringIteratorHasNext(obj);
 
 * stringIteratorFree(obj);
*/
