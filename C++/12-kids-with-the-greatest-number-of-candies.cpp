/*
https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
*/
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int num_kids = candies.size(), max_cadies;
        vector<bool> res(num_kids);
        
        max_cadies = candies[0];
        for (int i = 1; i < num_kids; i++) {
            if (candies[i] > max_cadies)
                max_cadies = candies[i];
        }
        
        for (int i = 0; i < num_kids; i++) {
            res[i] = candies[i] + extraCandies  >= max_cadies;
        }
        
        return res;
    }
};
