/*
https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
*/
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int len = arr.size();
        vector<pair<int, int>> popcnt(len);
        vector<int> res(len);
        
        for (int i = 0; i < len; i++) {
            popcnt[i] = make_pair(arr[i], __builtin_popcount(arr[i]));
        }
        
        sort(popcnt.begin(), popcnt.end(), [](pair<int, int> &p1, pair<int, int> &p2){
            if (p1.second != p2.second)
                return p1.second < p2.second;
            else
                return p1.first < p2.first;
        });
        
        for (int i = 0; i < len; i++) {
            res[i] = popcnt[i].first;
        }
        
        return res;
    }
};
