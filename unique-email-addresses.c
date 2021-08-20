/*
https://leetcode.com/problems/unique-email-addresses/

Interesting problem!!!
*/
#define CAPACITY 1000

struct elem {
  char* key;
  struct elem *next;
};

int hash_func (char *s)
{
  int sum = 0, i;
  
  for (i = 0; s[i]; i++) {
    sum += s[i];
  }
  
  return sum % CAPACITY;
}

bool find (struct elem **hash, char *key)
{
  struct elem *runner;
  int bucket = hash_func (key);
  
  runner = hash[bucket];
  while (runner) {
    if (!strcmp (runner->key, key))
      return true;
    runner = runner->next;
  }
  return false;
}

void insert (struct elem **hash, char *key)
{
  struct elem *new_elem;
  int bucket = hash_func (key);
  
  new_elem = (struct elem *) malloc (sizeof (*new_elem));
  new_elem->key = key;
  new_elem->next = hash[bucket];
  hash[bucket] = new_elem;
}

void sanitize (char *s)
{
  bool at_found = false;
  
  char* plus_idx = strchr (s, '+'), *at_idx = strchr (s, '@');
  
  if (plus_idx && at_idx > plus_idx) {
    //remove all the charaters from + to @
    while (*at_idx) {
      *plus_idx = *at_idx;
      plus_idx++;
      at_idx++;
    }
    *plus_idx = '\0';
  }
  
  char *dot_idx = strchr (s, '.');
  at_idx = strchr (s, '@');
  if (dot_idx && at_idx > dot_idx) {
    //remove all . up to @
    char *src = dot_idx + 1;
    while (*src) {
      if  (*src == '@')
        at_found = true;
      if (at_found || *src != '.') {
        *dot_idx = *src;
        dot_idx++;
        src++;
      } else {
        src++;
      }
    }
    *dot_idx = '\0';
  }
}

int numUniqueEmails(char ** emails, int emailsSize){
  int i, count = 0;
  struct elem *hash[CAPACITY] = {NULL};
  
  for (i = 0; i < emailsSize; i++) {
    sanitize (emails[i]);
    if (!find (hash, emails[i])) {
      insert (hash, emails[i]);
      count++;
    }
  }
  return count;
}
