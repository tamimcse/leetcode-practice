/*
https://leetcode.com/problems/3sum/
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int target_sum;
        
        sort (nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            target_sum = 0 - nums[i];
            unordered_set<int> set;
            for (int j = i + 1; j < nums.size();) {
                if (set.count(target_sum - nums[j])) {
                    vector<int> inner (3);
                    inner[0] = nums[i];
                    inner[1] = nums[j];
                    inner[2] = target_sum - nums[j];
                    res.push_back(inner);
                    j++;
                    while (j < nums.size() && nums[j] == nums[j-1])
                        j++;
                    continue;
                }
                set.insert(nums[j]);
                j++;
            }
        }
        return res;
    }
};
