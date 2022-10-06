/*
https://leetcode.com/problems/kth-missing-positive-number/
*/
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i = 0;
        int cur = 1;
        
        while (k > 0) {
            if (i < arr.size() && cur < arr[i]) {
                cur++;
                k--;
            } else if (i < arr.size() && cur == arr[i]){
                cur++;
                i++;
            } else {
                cur++;
                k--;
            }
        }
        
        return cur - 1;
    }
};
