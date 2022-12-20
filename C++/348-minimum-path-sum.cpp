/*
https://leetcode.com/problems/minimum-path-sum/
*/

/*********This causes TLE ************/
struct Pos {
    int x, y, sum;
    Pos (int x_, int y_, int sum_) {
        x = x_;
        y = y_;
        sum = sum_;
    }
    Pos () {
        x = 0;
        y = 0;
        sum = 0;
    }
};
struct HashFunc {
    int operator()(const pair<int,int> p) const {
        return ((long long)p.first * p.second) % 100;
    }
};
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        queue<Pos> q;
        Pos cur;
        int m = grid.size(), n = grid[0].size();
        int res = INT_MAX;
        unordered_map<pair<int,int>, int, HashFunc> hash;

        q.push(Pos(0, 0, grid[0][0]));
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            auto it = hash.find(make_pair(cur.x, cur.y));
            if (it != hash.end()) {
                if (cur.sum >= it->second)
                    continue;
            }
            hash[make_pair(cur.x, cur.y)] = cur.sum;
            if (cur.x == m - 1 && cur.y == n - 1) {
                res = min  (res, cur.sum);
            }
            if (cur.x + 1 < m) {
                q.push(Pos(cur.x + 1, cur.y, cur.sum + grid[cur.x + 1][cur.y]));
            }
            if (cur.y + 1 < n) {
                q.push(Pos(cur.x, cur.y + 1, cur.sum + grid[cur.x][cur.y + 1]));
            }
        }
        return res;
    }
};


/*********This solution works********/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        for (int i = 1; i < n; i++)
            grid[0][i] += grid[0][i-1];

        for (int i = 1; i < m; i++)
            grid[i][0] += grid[i-1][0];
            
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }

        return grid[m-1][n-1];
    }
};
