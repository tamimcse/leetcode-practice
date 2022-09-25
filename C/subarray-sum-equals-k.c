/*
https://leetcode.com/problems/subarray-sum-equals-k/
*/
#define CAPACITY 1000

struct elem {
  int key;
  int count;
  struct elem *next;
};

struct elem* exist (struct elem **hash, int key)
{
  struct elem *runner;
  int bucket = abs (key) % CAPACITY;
  
  runner = hash[bucket];
  while (runner) {
    if (runner->key == key)
      return runner;
    runner = runner->next;
  }
  return NULL;
}

void insert (struct elem **hash, int key)
{
  int bucket = abs (key) % CAPACITY;
  struct elem *new_node = (struct elem *) malloc (sizeof (*new_node));
  
  new_node->key = key;
  new_node->count = 1;
  new_node->next = hash[bucket];
  hash[bucket] = new_node;
}

int subarraySum(int* nums, int numsSize, int k){
  int i, j, sum, count = 0;
  int *prefix_sum = (int *) malloc (numsSize * sizeof (int));
  struct elem *hash[CAPACITY] = {NULL};
  struct elem *ret;
  
  prefix_sum[0] = nums[0];
  for (i = 1; i < numsSize; i++)
    prefix_sum[i] = prefix_sum[i-1] + nums[i];
  
  for (i = 0; i < numsSize; i++) {
    if (prefix_sum[i] == k)
      count++;
    ret = exist(hash, prefix_sum[i]-k);
    if (ret)
      count += ret->count;
    ret = exist(hash, prefix_sum[i]);
    if (!ret)
      insert (hash, prefix_sum[i]);
    else
      ret->count++;
  }
  return count;
}
