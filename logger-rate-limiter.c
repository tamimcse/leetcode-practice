/*
https://leetcode.com/problems/logger-rate-limiter/

Design a logger system that receives a stream of messages along with their timestamps. Each unique message should only be printed at most every 10 seconds (i.e. a message printed at timestamp t will prevent other identical messages from being printed until timestamp t + 10).

All messages will come in chronological order. Several messages may arrive at the same timestamp.

Implement the Logger class:

Logger() Initializes the logger object.
bool shouldPrintMessage(int timestamp, string message) Returns true if the message should be printed in the given timestamp, otherwise returns false.
 

Example 1:

Input
["Logger", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage"]
[[], [1, "foo"], [2, "bar"], [3, "foo"], [8, "bar"], [10, "foo"], [11, "foo"]]
Output
[null, true, true, false, false, false, true]

Explanation
Logger logger = new Logger();
logger.shouldPrintMessage(1, "foo");  // return true, next allowed timestamp for "foo" is 1 + 10 = 11
logger.shouldPrintMessage(2, "bar");  // return true, next allowed timestamp for "bar" is 2 + 10 = 12
logger.shouldPrintMessage(3, "foo");  // 3 < 11, return false
logger.shouldPrintMessage(8, "bar");  // 8 < 12, return false
logger.shouldPrintMessage(10, "foo"); // 10 < 11, return false
logger.shouldPrintMessage(11, "foo"); // 11 >= 11, return true, next allowed timestamp for "foo" is 11 + 10 = 21
*/

#define CAPACITY 1000

struct elem {
  char* key;
  int val;
  struct elem *next;
};

int calc_hash (char *key)
{
  int i, sum;
  
  sum = 0;
  for (i = 0; key[i]; i++) {
    sum += key[i];
  }
  return sum % CAPACITY;
}

struct elem* find (struct elem **hash, char* key)
{
  struct elem *runner;
  int bucket = calc_hash (key);
  
  runner = hash[bucket];
  while (runner) {
    if (!strcmp (runner->key, key))
      return runner;
    runner = runner->next;
  }
  return NULL;
}

void insert (struct elem **hash, char *key, int val)
{
  struct elem *new_elem;
  int bucket = calc_hash (key);
  
  new_elem = (struct elem *) malloc (sizeof (*new_elem));
  new_elem->key = key;
  new_elem->val = val;
  new_elem->next = hash[bucket];
  hash[bucket] = new_elem;
}

typedef struct {
    struct elem *hash[CAPACITY];
} Logger;

/** Initialize your data structure here. */

Logger* loggerCreate() {
    Logger *l = (Logger *) calloc (1, sizeof (*l));
    return l;
}

/** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
bool loggerShouldPrintMessage(Logger* obj, int timestamp, char * message) {
  struct elem *ret = find (obj->hash, message);
  if (!ret) {
    insert (obj->hash, message, timestamp);
    return true;
  }
  if (timestamp - ret->val >= 10) {
    ret->val = timestamp;
    return true;
  } else {
    return false;
  }
}

void loggerFree(Logger* obj) {
    free (obj);
}

/**
 * Your Logger struct will be instantiated and called as such:
 * Logger* obj = loggerCreate();
 * bool param_1 = loggerShouldPrintMessage(obj, timestamp, message);
 
 * loggerFree(obj);
*/
