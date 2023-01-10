/*
https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

Interesting problem.
*/
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort (horizontalCuts.begin(), horizontalCuts.end());
        sort (verticalCuts.begin(), verticalCuts.end());
        horizontalCuts.insert(horizontalCuts.begin(), 0);
        horizontalCuts.push_back(h);
        verticalCuts.insert(verticalCuts.begin(), 0);
        verticalCuts.push_back(w);

        int max_width = 0;
        for (int i = 1; i < horizontalCuts.size(); i++) {
            max_width = max (max_width, horizontalCuts[i] - horizontalCuts[i-1]);
        }

        int max_height = 0;
        for (int i = 1; i < verticalCuts.size(); i++) {
            max_height = max (max_height, verticalCuts[i] - verticalCuts[i-1]);
        }

        return ((long long)max_width * max_height) % 1000000007;
    }
};
