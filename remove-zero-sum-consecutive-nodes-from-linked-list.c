/*
https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#define CAPACITY 1000

struct elem {
  int key;
  struct ListNode *val;
  struct node *next;
};

struct ListNode* find (struct elem **hash, int key)
{
  struct elem *runner;
  int bucket = abs (key) % CAPACITY;
  
  runner = hash[bucket];
  while (runner) {
    if (runner->key == key)
      return runner->val;
    runner = runner->next;
  }
  return NULL;
}

void insert (struct elem **hash, int key, struct ListNode* val)
{
  struct elem *new_elem;
  int bucket = abs (key) % CAPACITY;
  
  new_elem = (struct elem *) malloc (sizeof (*new_elem));
  new_elem->key = key;
  new_elem->val = val;
  new_elem->next = hash[bucket];
  hash[bucket] = new_elem;
}

void clean_hash (struct elem **hash)
{
  int i;
  
  for (i = 0; i < CAPACITY; i++)
    hash[i] = NULL;
}

struct ListNode* removeZeroSumSublists(struct ListNode* head){
  struct elem *hash[CAPACITY] = {NULL};
  struct ListNode *runner = head;
  struct ListNode *ret;
  int prefix_sum = 0;
  struct ListNode *new_head = head;
  
  while (runner) {
    prefix_sum += runner->val;
    if (!prefix_sum) {
      new_head = runner->next;
      runner = new_head;
      prefix_sum = 0;
      clean_hash (hash);
      continue;
    }
    ret = find (hash, prefix_sum);
    if (ret) {
      ret->next = runner->next;
      runner = new_head;
      prefix_sum = 0;
      clean_hash (hash);
      continue;
    } else {
      insert (hash, prefix_sum, runner);
    }    
    runner = runner->next;
  }
  return new_head;
}
