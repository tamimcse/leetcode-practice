/*
https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

Very very very very interenting problem!!
*/
struct node {
  bool leaf;
  struct node *child[2];
  int num;
};

void insert (struct node *root, int num, int num_bits)
{
  int i, bit;
  struct node *runner = root;
  
  for (i = 0; i < num_bits; i++) {
    bit = (num >> (num_bits - 1 - i)) & 1;
    if (!runner->child[bit])
      runner->child[bit] = (struct node *) calloc (1, sizeof (*runner));
    runner = runner->child[bit];
  }
  runner->leaf = true;
  runner->num = num;
}

int find_max (struct node *root, int num, int num_bits)
{
  int i, bit;
  struct node *runner = root;
  
  for (i = 0; i < num_bits; i++) {
    bit = (num >> (num_bits - 1 - i)) & 1;
    if (bit == 1) {
      if (runner->child[0])
        runner = runner->child[0];
      else
        runner = runner->child[1];
    } else {
      if (runner->child[1])
        runner = runner->child[1];
      else
        runner = runner->child[0];
    }
  }
  return runner->num;
}

int findMaximumXOR(int* nums, int numsSize){
  int i, j, max, num_bits, ret;
  struct node root;
  
  memset (&root, 0, sizeof (struct node));
    
  max = nums[0];
  for (i = 1; i < numsSize; i++) {
    if (nums[i] > max)
      max = nums[i];
  }
  
  num_bits = log2 (max) + 1;
  
  for (i = 0; i < numsSize; i++) {
    insert (&root, nums[i], num_bits);
  }
  
  max = -1;
  for (i = 0; i < numsSize; i++) {
    ret = find_max (&root, nums[i], num_bits);
    if ((ret ^ nums[i]) > max)
      max = ret ^ nums[i];
  }
  return max;
}
