/*
https://leetcode.com/problems/copy-list-with-random-pointer/
*/
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

#define CAPACITY 1000

struct elem {
  struct Node* key;
  struct Node* val;
  struct elem *next;
};

struct Node* find (struct elem **hash, struct Node* key)
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

void insert (struct elem **hash, struct Node* key, struct Node* val)
{
  struct elem *new_elem;
  int bucket = abs (key) % CAPACITY;
  
  new_elem = (struct elem *) malloc (sizeof (*new_elem));
  new_elem->key = key;
  new_elem->val = val;
  new_elem->next = hash[bucket];
  hash[bucket] = new_elem;
}

struct Node* copyRandomList(struct Node* head) {
	struct elem *hash[CAPACITY] = {NULL};
  struct Node *new_head, *runner1, *prev1, *prev2, *new_node, *runner2;
  
  if (!head)
    return NULL;
  
  new_head = (struct Node *) calloc (1, sizeof (*new_head));
  new_head->val = head->val;
  insert (hash, head, new_head);
  
  runner1 = head->next;
  prev1 = head;
  prev2 = new_head;
  while (runner1) {
    new_node = (struct Node *) calloc (1, sizeof (*new_node));
    new_node->val = runner1->val;
    insert (hash, runner1, new_node);
    prev2->next = new_node;
    prev1 = runner1;
    runner1 = runner1->next;
    prev2 = new_node; 
  }
  
  runner1 = head;
  runner2 = new_head;
  while (runner1) {
    if (runner1->random)
      find (hash, runner1)->random = find (hash, runner1->random);
    runner1 = runner1->next;
    runner2 = runner2->next;
  }
  
  return new_head;
}
