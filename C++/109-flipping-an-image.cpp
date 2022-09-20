/*
https://leetcode.com/problems/flipping-an-image/
*/
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int num_row = image.size(), num_col = image[0].size();
        
        vector<vector<int>> res(num_row);
        for (int i = 0; i < num_row; i++) {
            res[i].resize(num_col);
        }
        
        for (int row = 0; row < num_row; row++) {
            for (int col = 0; col < num_col; col++) {
                res[row][num_col - 1 - col] = image[row][col];
            }
        }
        
        for (int row = 0; row < num_row; row++) {
            for (int col = 0; col < num_col; col++) {
              res[row][col] = res[row][col] ^ 1;  
            }
        }

        
        return res;
    }
};
