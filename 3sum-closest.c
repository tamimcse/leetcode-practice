/*
https://leetcode.com/problems/3sum-closest/
*/
int cmp (const void *a, const void *b)
{
  return *((int *)a) - *((int *)b);
}

int threeSumClosest(int* nums, int numsSize, int target){
  int i, j, start, end, to_find, sum, closest_sum, delta = 100000000, op1, op2, op3, op4, min_delta;
    
  qsort (nums, numsSize, sizeof (int), cmp);  
    
  for (i = 0; i < numsSize - 2; i++) {
    start = i + 1;
    end =  numsSize - 1; 
    sum =  nums[i] + nums[start] + nums[end];
    min_delta = abs (target - nums[i] - nums[start] - nums[end]);
    while (end > start) {
      if (end == start + 1) {
        op4 = abs (target - nums[i] - nums[start] - nums[end]);
        if (op4 <= min_delta) {
            min_delta = op4;
            sum = nums[i] + nums[start] + nums[end];
        }
        break;  
      }  
      op1 = abs (target - nums[i] - nums[start + 1] - nums[end]);
      op2 = abs (target - nums[i] - nums[start] - nums[end - 1]);
      op3 = abs (target - nums[i] - nums[start] - nums[end]);
      if (op1 < op2) {
        if (op1 < min_delta) {
            sum = nums[i] + nums[start + 1] + nums[end];
            min_delta = op1;
        }
        start++;
      } else {
        if (op2 < min_delta) {
            sum = nums[i] + nums[start] + nums[end - 1];
            min_delta = op2;
        }
        end--;
      }
    }
    if (min_delta < delta) {
      closest_sum = sum;
      delta = min_delta; 
    }
  }
    
  return closest_sum;  
}
