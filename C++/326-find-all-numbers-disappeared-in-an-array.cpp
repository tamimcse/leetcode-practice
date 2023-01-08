/*
https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

Implement using both extra space and O(1) space
*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        vector<int> freq(n+1);

        for (auto i : nums) {
            freq[i]++;
        }

        for (int i = 1; i < n+1; i++) {
            if (!freq[i])
                res.push_back(i);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;

        for (int i = 0; i < n; i++) {
            int num = abs(nums[i]) - 1;
            if (nums[num] > 0)
                nums[num] = -nums[num];
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0)
                res.push_back(i+1);
        }
        return res;
    }
};
