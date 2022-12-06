/*
https://leetcode.com/problems/detect-cycles-in-2d-grid/
*/

class Solution {
    int adj[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    void dfs (vector<vector<char>>& grid, int x, int y,
              vector<vector<int>>& visit, bool &res,
              int cur_val, int dir) {
        int m = grid.size(), n = grid[0].size();
        visit[x][y] = cur_val;

        for (int i = 0; i < 4; i++) {
            if ((dir == 0 && i == 2) || (dir == 1 && i == 3) ||
                (dir == 2 && i == 0) || (dir == 3 && i == 1)) {
                continue;        
            }
            int cur_x = x + adj[i][0];
            int cur_y = y + adj[i][1];
            if (cur_x >= 0 && cur_x < m && cur_y >= 0 && cur_y < n) {
                if (visit[cur_x][cur_y] == cur_val) {
                    res = true;
                    return;
                }
                if ((!visit[cur_x][cur_y]) && (grid[x][y] == grid[cur_x][cur_y])) {
                    dfs (grid, cur_x, cur_y, visit, res, cur_val, i);
                }
            }
        }
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visit(m);
        
        for (auto &e : visit)
            e.resize(n);
        
        int cur_val = 1;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visit[i][j]) {
                    bool res = false;
                    dfs (grid, i, j, visit, res, cur_val, -1);
                    if (res)
                        return true;
                    cur_val++;
                }
            }
        }
        return false;
    }
};
