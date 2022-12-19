/*
https://leetcode.com/problems/target-sum/

Very interesting problem.
*/

/********This gets TLE*************/
class Solution {
    int calc_sum (vector<int>& nums, vector<char>& ops) {
        int n = nums.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += ops[i] == '+' ? nums[i] : -nums[i];
        }
        return sum;
    }
    void findTargetSumWays(vector<int>& nums, int target,
                        vector<char>& ops, int idx, int &count) {
        int n = nums.size();
        if (idx == n) {
            if (calc_sum (nums, ops) == target)
                count++;
            return;
        }
        ops[idx] = '+';
        findTargetSumWays (nums, target, ops, idx + 1, count);
        ops[idx] = '-';
        findTargetSumWays (nums, target, ops, idx + 1, count);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<char> ops(nums.size());
        int count = 0;

        findTargetSumWays (nums, target, ops, 0, count);
        return count;
    }
};


/*********This solution works************/
class Solution {

    void findTargetSumWays(vector<int>& nums, int target, int idx, int &count) {
        int n = nums.size();
        if (idx == n) {
            if (target == 0)
                count++;
            return;
        }

        findTargetSumWays (nums, target + nums[idx], idx + 1, count);
        findTargetSumWays (nums, target - nums[idx], idx + 1, count);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int count = 0;

        findTargetSumWays (nums, target, 0, count);
        return count;
    }
};
