/*
https://leetcode.com/problems/beautiful-arrangement/
*/

bool is_beautiful (int *arr, int len)
{
  int i; 
  
  for (i = 0; i < len; i++) {
    if (arr[i] % (i + 1) != 0 && (i + 1) % arr[i] != 0)
      return false;
  }
  return true;
}

void backtrack (int *arr, int len, int count, int *hash, int *res_count)
{
  int i;
  
  if (len == count) {
    if (is_beautiful (arr, len))
      (*res_count)++;
    return;
  }
  
  for (i = 0; i < len; i++) {
    if (hash[i])
      continue;
    hash[i] = 1;
    arr[count] = i + 1;
    //critical improvement
    if (is_beautiful (arr, count + 1))
      backtrack (arr, len, count + 1, hash, res_count);
    hash[i] = 0;
  }
}

int countArrangement(int n){
  int *arr = (int *) malloc (n * sizeof (int));
  int count = 0;
  int *hash = (int *) calloc (n, sizeof (int));
  int num_beautiful = 0;
  
  backtrack (arr, n, 0, hash, &num_beautiful);
  return num_beautiful;
}
