/*
https://leetcode.com/problems/interval-list-intersections/
*/
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int m = firstList.size(), n = secondList.size();

        for (int i = 0, j = 0; i < m && j < n;) {
            int intersecx = max (firstList[i][0], secondList[j][0]);
            int intersecy = min (firstList[i][1], secondList[j][1]);
            if (intersecx <= intersecy)
                res.push_back({intersecx, intersecy});
            if (firstList[i][1] <= secondList[j][1])
                i++;
            else
                j++;
        }
        return res;
    }
};
