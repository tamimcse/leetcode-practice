/*
https://leetcode.com/problems/3sum-smaller/
*/
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size();
        int count = 0, new_target, final_target;

        sort (nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            new_target = target - nums[i];
            for (int j = i + 1, k = n - 1; j < n - 1; j++) {
                final_target = new_target - nums[j] ;
                while (k >= j && nums[k] >= final_target)
                    k--;
                if (k >= j)
                    count += k - j;    
            }
        }
        return count;
    }
};
