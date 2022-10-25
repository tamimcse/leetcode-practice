/*
https://leetcode.com/problems/number-of-islands/
*/
class Solution {
    bool isLand (vector<vector<char>> &grid, int row, int col) {
        if (row >= grid.size())
            return false;
        if (col >= grid[0].size())
            return false;
        if (row < 0 || col < 0)
            return false;
        return grid[row][col] == '1';
    }
    void dfs(vector<vector<char>>& grid, int row, int col,
             vector<vector<bool>> &visited) {
        if (visited[row][col])
            return;
        visited[row][col] = true;
        if (isLand(grid, row + 1, col))
            dfs (grid, row + 1, col, visited);
        if (isLand(grid, row, col + 1))
            dfs (grid, row, col + 1, visited);
        if (isLand(grid, row, col - 1))
            dfs (grid, row, col - 1, visited);
        if (isLand(grid, row - 1, col))
            dfs (grid, row - 1, col, visited);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<bool>> visited(m);
        for (auto &e : visited) {
            e.resize(n);
        }
        
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    count++;
                    cout << i << " " << j << endl;
                    dfs (grid, i, j, visited);
                }
            }
        }
        
        return count;
    }
};
