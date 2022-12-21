/*
https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
*/
class Solution {
    int adj[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

    void dfs (vector<vector<int>>& matrix, vector<vector<int>> &visit,
                vector<vector<int>> &pathlen, int x, int y) {
        int m = matrix.size(), n = matrix[0].size();
        int path = 0, adj_x, adj_y;

        visit[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            adj_x = x + adj[i][0];
            adj_y = y + adj[i][1];
            if (adj_x < 0 || adj_y < 0 || adj_x >= m || adj_y >= n ||
                visit[adj_x][adj_y] == 1 || matrix[x][y] >= matrix[adj_x][adj_y])
                continue;
            if (visit[adj_x][adj_y] == 2) {
                path = max (path, pathlen[adj_x][adj_y]);
            } else if (visit[adj_x][adj_y] == 0) {
                dfs(matrix, visit, pathlen, adj_x, adj_y);
                path = max (path, pathlen[adj_x][adj_y]);
            }
        }
        visit[x][y] = 2;
        pathlen[x][y] = 1 + path;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> visit(m);
        vector<vector<int>> pathlen(m);

        for (int i = 0; i < m; i++) {
            visit[i].resize(n);
            pathlen[i].resize(n);
        }
            
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visit[i][j])
                    continue;
                dfs (matrix, visit, pathlen, i, j);
            }
        }

        int res = pathlen[0][0];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res = max (res, pathlen[i][j]);
            }
        }
        return res;
    }
};
