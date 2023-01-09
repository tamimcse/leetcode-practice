/*
https://leetcode.com/problems/find-k-closest-elements/

Interesting problem
*/
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort (arr.begin(), arr.end(), [&](int a, int b) {
            if (abs(x - a) == abs(x - b))
                return a < b;
            return abs(x - a) < abs(x - b);
        });

        vector<int> res (arr.begin(), arr.begin() + k);
        sort (res.begin(), res.end());
        return res;        
    }
};
