/*
https://leetcode.com/problems/search-a-2d-matrix-ii/
*/

class Solution {
    int arr[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    void dfs (vector<vector<int>>& matrix, int target,
              vector<vector<bool>>& visit, int row, int col, bool &res) {
        int adj_row, adj_col;
        int m = matrix.size(), n = matrix[0].size();
        
        if (visit[row][col])
            return;
        if (res)
            return;
        
        visit[row][col] = true;
        
        if (matrix[row][col] == target) {
            res = true;
            return;
        }
        
        if (target > matrix[row][col]) {
            for (int i = 0; i < 2; i++) {
                adj_row = row + arr[i][0];
                adj_col = col + arr[i][1];
                if (adj_row < 0 || adj_col < 0 || adj_row >= m || 
                    adj_col >= n || visit[adj_row][adj_col])
                    continue;
                dfs(matrix, target, visit, adj_row, adj_col, res);
            }            
        } else {
            for (int i = 2; i < 4; i++) {
                adj_row = row + arr[i][0];
                adj_col = col + arr[i][1];

                if (adj_row < 0 || adj_col < 0 || adj_row >= m || 
                    adj_col >= n || visit[adj_row][adj_col])
                    continue;
                dfs(matrix, target, visit, adj_row, adj_col, res);
            }
        }

    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> visit(m);
        bool res = false;
        
        for (int i = 0; i < m; i++)
            visit[i].resize(n);
        
        dfs(matrix, target, visit, 0, n - 1, res);
        return res;
    }
};
