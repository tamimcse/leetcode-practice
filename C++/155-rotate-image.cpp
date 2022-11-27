/*
https://leetcode.com/problems/rotate-image/
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int row = 0, col = 0;
        
        int num_col = n - 1;
        for (int i = 0; i < n/2; i++) {
            for (int j = i, k = 0; k < num_col; j++, k++) {
                int cur_row = i, cur_col = j;
                int to_replace = matrix[cur_row][cur_col];
                for (int p = 0; p < 4; p++) {
                    int new_to_replace = matrix[cur_col][n - 1 - cur_row];
                    matrix[cur_col][n - 1 - cur_row] = to_replace;
                    to_replace = new_to_replace;
                    int tmp = cur_row;
                    cur_row = cur_col;
                    cur_col = n - 1 - tmp;
                }
            }
            num_col -= 2;
        }
    }
};
