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
