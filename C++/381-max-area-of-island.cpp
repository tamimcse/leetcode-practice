/*
https://leetcode.com/problems/max-area-of-island/
*/
class Solution {
    int adj [4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    
    void dfs(vector<vector<int>>& grid, int x, int y,
             vector<vector<int>>& visit, int &count) {
        int m = grid.size(), n = grid[0].size();
        int adj_x, adj_y;
        visit[x][y] = 1;
        count++;
        
        for (int i = 0; i < 4; i++) {
            adj_x = x + adj[i][0];
            adj_y = y + adj[i][1];
            if (adj_x >= 0 && adj_x < m && adj_y >= 0 && adj_y < n) {
                if (grid[adj_x][adj_y] && !visit[adj_x][adj_y])
                    dfs (grid, adj_x, adj_y, visit, count);
            }
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visit(m);
        int res = 0;
        
        for (auto &e : visit)
            e.resize(n);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    int count = 0;
                    dfs (grid, i, j, visit, count);
                    res = max (count, res);
                }
            }
        }
        return res;
    }
};
