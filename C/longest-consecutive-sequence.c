/*
https://leetcode.com/problems/longest-consecutive-sequence/

Very very intersing problem!!!

Sometimes, you may come across a problem where you need to check if you came through this path. This problem particularly arise in sequence building. In that, check if you can solve this using DFS/BFS. Usually you can. An example of such problem is longest-consecutive-sequence.

But, note that, when you really want to create a sequence, do you really need to start from the any node. For instance, in longest-consecutive-sequence problem, you are given an array. The first element of the array may not be the first element of the sequence. This is why, you may need to look both ways to create sequence. Solving this problem with DFS and BFS also involve havinhg visit array so that we don't visit an element if we visited before. But, all this problem can be simplified if we only start with elements that's the start of a sequence. In that case, we don't need to look bi-directionally. We only look unidirectionally. For instance, Approach #3

https://leetcode.com/problems/longest-consecutive-sequence/solution/
*/
#define NUM_BUCKET 1000 

struct node {
  int val;
  struct node *next;
};

bool exists (struct node **hash, int to_find)
{
  struct node *runner;
  int bucket = abs (to_find) % NUM_BUCKET;
  
  runner = hash[bucket];
  while (runner) {
    if (runner->val == to_find)
      return true;
    runner = runner->next;
  }
  return false;
}

void insert (struct node **hash, int to_insert)
{
  struct node *new_node;
  int bucket;
  
  if (exists (hash, to_insert))
    return;
  
  bucket = abs (to_insert) % NUM_BUCKET;
  new_node = (struct node *) malloc (sizeof (*new_node));
  new_node->val = to_insert;
  new_node->next = hash[bucket];
  hash[bucket] = new_node;
}

int longestConsecutive(int* nums, int numsSize){
  struct node *hash[NUM_BUCKET] = {NULL};
  int i, j, k, curr, max = 0, seq_count;
  
  for (i = 0; i < numsSize; i++) {
    insert (hash, nums[i]);
  }
  
  for (i = 0; i < numsSize; i++) {
    if (exists (hash, nums[i] - 1))
      continue;
    seq_count = 1;
    curr = nums[i];
    while (exists (hash, curr + 1)) {
      seq_count++;
      curr++;
    }
    if (seq_count > max)
      max = seq_count;
  }
  
  return max;
}
