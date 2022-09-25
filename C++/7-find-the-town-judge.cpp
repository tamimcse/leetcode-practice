/*
https://leetcode.com/problems/find-the-town-judge/
*/
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int trustCount[1001] = {0};
        int trustsMap[1001] = {0};
        
        if (n == 1)
            return 1;
        
        for (auto e : trust) {
            trustsMap[e[0]] = 1;
            trustCount[e[1]]++;
        }
        
        for (int i = 1; i < 1001; i++) {
            if (trustCount[i] == n - 1 && !trustsMap[i]) {
                return i;
            }
        }
        
        return -1;
    }
};
