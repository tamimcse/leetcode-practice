/*
https://leetcode.com/problems/shortest-path-in-binary-matrix/
*/
struct Point {
    int x, y, level;
    Point (int x_, int y_, int level_) {
        x = x_;
        y = y_;
        level = level_;
    }
};

class Solution {
    int adj[8][2] = {{0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<Point> q;
        int x, y, level, adj_x, adj_y;
        int n = grid.size();
        vector<vector<bool>> visit(n);

        if (grid[0][0])
            return -1;

        for (int i = 0; i < n; i++)
            visit[i].resize(n);

        q.push(Point(0, 0, 1));
        visit[0][0] = true;
        while (!q.empty()) {
            x = q.front().x;
            y = q.front().y;
            level = q.front().level; 
            q.pop();
            if (x == n - 1 && y == n - 1)
                return level;
            for (int i = 0; i < 8; i++) {
                adj_x = x + adj[i][0];
                adj_y = y + adj[i][1];
                if (adj_x >= 0 && adj_y >= 0 && adj_x < n && adj_y < n &&
                    !visit[adj_x][adj_y] && grid[adj_x][adj_y] == 0) {
                    q.push(Point(adj_x, adj_y, level + 1));
                    visit[adj_x][adj_y] = true;
                }
            }
        }
        return -1;
    }
};
