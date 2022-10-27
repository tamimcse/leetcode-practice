/*
https://leetcode.com/problems/h-index/
*/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort (citations.begin(), citations.end());
        
        int j = 1;
        for (int i = n - 1; i >= 0; i--, j++) {
            if (citations[i] < j)
                break;
        }
        return j-1;
    }
};
