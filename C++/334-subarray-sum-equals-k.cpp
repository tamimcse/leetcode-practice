/*
https://leetcode.com/problems/subarray-sum-equals-k/

Very interesting problem!!!!
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixSum(n);
        int count = 0;
        unordered_map<int, int> hash;

        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }

        for (int i = 0; i < n; i++) {
            if (prefixSum[i] == k)
                count++;
        }

        for (int i = 0; i < n; i++) {
            auto it = hash.find(prefixSum[i] - k);
            if (it != hash.end())
                count += it->second;
            hash[prefixSum[i]]++;    
        }
        return count;
    }
};
