/*
https://leetcode.com/problems/fraction-to-recurring-decimal/
*/
#define CAPACITY 1000

struct elem {
  long key;
  long val;
  struct elem *next;
};

struct elem* find (struct elem **hash, long key)
{
  struct elem *runner;
  long bucket = labs (key) % CAPACITY;
  
  runner = hash[bucket];
  while (runner) {
    if (runner->key == key)
      return runner;
    runner = runner->next;
  }
  return NULL;
}

void insert (struct elem **hash, long key, long val)
{
  struct elem *new_elem;
  long bucket = labs (key) % CAPACITY;
  
  new_elem = (struct elem *) malloc (sizeof (*new_elem));
  new_elem->key = key;
  new_elem->val = val;
  new_elem->next = hash[bucket];
  hash[bucket] = new_elem;
}

char * fractionToDecimal(int numerator, int denominator){
  char *ret = (char *) calloc (2001, sizeof (char));
  char *res = (char *) calloc (2001, sizeof (char));
  char fraction[20001] = {0};
  long num, len, i, j;
  struct elem *hash[CAPACITY] = {NULL};
  struct elem *hash_entry;
  long up, down;
  
  i = 0;
  if ((numerator > 0 && denominator < 0) || (numerator < 0 && denominator > 0))
    res[i++] = '-';
  
  up = labs (numerator);
  down = labs (denominator);
  
  if (up >= down) {
    num = up / down;
    up = up % down;
    sprintf (res, "%s%ld", res, num);
  } else {
    res[i++] = '0';
  }
  len = strlen (res);
  if (!up)
    return res;
  up = up * 10;
  res[len++] = '.';

  i = 0;
  while (up) {
    hash_entry = find (hash, up);
    if (hash_entry) {
      fraction[i+1] = ')';
      for (j = i-1; j >= hash_entry->val; j-- )
        fraction[j+1] = fraction[j];
      fraction[hash_entry->val] = '(';
      break; 
    }
    insert (hash, up, i);
    if (up < down) {
      up *= 10;
      fraction[i++] = '0';      
    } else {
      fraction[i++] = '0' + up/down;
      up = (up % down) * 10;      
    }
  }
  sprintf (ret, "%s%s", res, fraction);    
  return ret;
}
