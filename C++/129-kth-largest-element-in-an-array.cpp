/*
https://leetcode.com/problems/kth-largest-element-in-an-array/
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (auto e : nums) {
            if (pq.size() < k) {
                pq.push(e);
                continue;
            }
            if (pq.top() >= e)
                continue;
            pq.pop();
            pq.push(e);
        }
        
        return pq.top();
    }
};
