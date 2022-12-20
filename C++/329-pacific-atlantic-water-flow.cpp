/*
https://leetcode.com/problems/pacific-atlantic-water-flow/
*/
class Solution {
    int adj[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

    void dfs (vector<vector<int>>& heights, vector<vector<bool>> &atlantic,
              vector<vector<bool>> &visit, int x, int y) {
        int m = heights.size(), n = heights[0].size();
        int adj_x, adj_y;
        atlantic[x][y] = true;
        visit[x][y] = true;

        for (int i = 0; i < 4; i++) {
            adj_x = x + adj[i][0];
            adj_y = y + adj[i][1];
            if (adj_x >= 0 && adj_x < m && adj_y >= 0 && adj_y < n &&
                !visit[adj_x][adj_y] && heights[adj_x][adj_y] >= heights[x][y]) {
                dfs (heights, atlantic, visit, adj_x, adj_y);
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> atlantic(m);
        vector<vector<bool>> pacific(m);
        vector<vector<bool>> visit1(m);
        vector<vector<bool>> visit2(m);
        vector<vector<int>> res;

        for (int i = 0; i < m; i++) {
            atlantic[i].resize(n);
            pacific[i].resize(n);
            visit1[i].resize(n);
            visit2[i].resize(n);
        }

        for (int i =  0; i < n; i++) {
            dfs (heights, atlantic, visit1, m-1, i);
        }
            
        for (int i =  0; i < m; i++) {
            dfs (heights, atlantic, visit1, i, n-1);
        }

        for (int i =  0; i < n; i++) {
            dfs (heights, pacific, visit2, 0, i);
        }
            
        for (int i =  0; i < m; i++) {
            dfs (heights, pacific, visit2, i, 0);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (atlantic[i][j] && pacific[i][j])
                    res.push_back({i, j});
            }
        }
        return res;
    }
};
