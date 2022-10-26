/*
https://leetcode.com/problems/search-a-2d-matrix-ii/

Very interesting problem. Must solve
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int row = 0, col = n -1;
        while (row >= 0 && col >= 0 && row < m && col < n) {
            if (matrix[row][col] == target)
                return true;
            else if (target > matrix[row][col])
                row++;
            else
                col--;
        }
        return false;
    }
};
