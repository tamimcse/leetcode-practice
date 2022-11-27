/*
https://leetcode.com/problems/search-a-2d-matrix/
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int start = 0, end = m * n - 1, row, col, mid;
        
        while (end >= start) {
            mid = (start + end) >> 1;
            row = mid / n;
            col = mid % n;
            if (matrix[row][col] == target)
                return true;
            if (target > matrix[row][col]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return false;
    }
};
