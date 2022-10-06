/*
https://leetcode.com/problems/toeplitz-matrix/
*/
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int num_row = matrix.size(), num_col = matrix[0].size();
        
        for (int row = 0, col = 0; col < num_col - 1; col++) {
            int num = matrix[row][col];
            int x = row;
            int y = col;
            while (x < num_row && y < num_col) {
                if (matrix[x][y] != num)
                    return false;
                x++;
                y++;
            }
        }
        
        for (int row = 1, col = 0; row < num_row - 1; row++) {
            int num = matrix[row][col];
            int x = row;
            int y = col;
            while (x < num_row && y < num_col) {
                if (matrix[x][y] != num)
                    return false;
                x++;
                y++;
            }
        }
        
        return true;
    }
};
