/*
https://leetcode.com/problems/3sum-closest/
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest_sum = nums[0] + nums[1] + nums[2];
        int diff = abs(target - closest_sum);
        int start, end;
        
        sort (nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            int cur_target = target - nums[i];
            start = i + 1;
            end = nums.size() - 1;
            int prev_diff = cur_target - nums[start] - nums[end];
            while (end > start) {
                int cur_sum = nums[start] + nums[end];
                if (abs(cur_sum + nums[i] - target)  < diff) {
                    diff = abs(cur_sum + nums[i] - target);
                    closest_sum = cur_sum + nums[i];
                }
                //if (abs(cur_sum + nums[i] - target) > prev_diff) {
                //    break;
                //}
                if (cur_target > cur_sum)
                    start++;
                else if (cur_target < cur_sum)
                    end--;
                else
                    return target;
               // prev_diff = distance(cur_sum + nums[i], target);
            }
        }
        return closest_sum;
    }
};
