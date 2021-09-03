/*
https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

Very very interesting problem!
*/
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
      int max_height = h, max_weight = w, res;
      unsigned int mod = 1000000007;
      
      std::sort (horizontalCuts.begin(), horizontalCuts.end());
      std::sort (verticalCuts.begin(), verticalCuts.end());
      
      max_height = horizontalCuts[0];
      for (int i = 1; i < horizontalCuts.size(); i++) {
        if (horizontalCuts[i] - horizontalCuts[i - 1] > max_height) {
          max_height = horizontalCuts[i] - horizontalCuts[i - 1];
        }
      }
      if (h - horizontalCuts[horizontalCuts.size() - 1] > max_height)
        max_height = h - horizontalCuts[horizontalCuts.size() - 1];
      
      max_weight = verticalCuts[0];
      for (int i = 1; i < verticalCuts.size(); i++) {
        if (verticalCuts[i] - verticalCuts[i - 1] > max_weight) {
          max_weight = verticalCuts[i] - verticalCuts[i - 1];
        }
      }
      if (w - verticalCuts[verticalCuts.size() - 1] > max_weight)
        max_weight = w - verticalCuts[verticalCuts.size() - 1];
      
      res =  ((long long) max_weight * max_height) % mod;
      return res;
    }
};
