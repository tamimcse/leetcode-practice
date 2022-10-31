/*
https://leetcode.com/problems/number-of-islands-ii/
*/
class Solution {
    int arr[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        int i, j, x, y, count;
        vector<vector<int>> visit(m);
        vector<int> res;
        
        for (int i = 0; i < m; i++)
            visit[i].resize(n);
        
        count = 0;
        for (auto &e : positions) {
            if (visit[e[0]][e[1]]) {
                res.push_back(count);
                continue;
            }
            vector<pair<int, int>> adj;
            unordered_set<int> us;
            for (int i = 0; i < 4; i++) {
                x = e[0] + arr[i][0];
                y = e[1] + arr[i][1];
                if (x >= 0 && y >= 0 && x < m && y < n) {
                    if (visit[x][y] && us.count(visit[x][y]) == 0) {
                        us.insert(visit[x][y]);
                        adj.push_back(make_pair(x, y));
                    }
                }
            }
            
            if (us.size() == 0) {
                visit[e[0]][e[1]] = e[0] * n + e[1] + 1;
                count++;
            } else {
                visit[e[0]][e[1]] = visit[adj[0].first][adj[0].second];
                unordered_set<int> set;
                set.insert(visit[e[0]][e[1]]);
                for (int i = 1; i < adj.size(); i++) {
                    if (set.count(visit[adj[i].first][adj[i].second]))
                        continue;
                    int tmp = visit[adj[i].first][adj[i].second];
                    for (int p = 0; p < m; p++) {
                        for (int q = 0; q < n; q++) {
                            if (visit[p][q] == tmp) {
                                visit[p][q] = visit[e[0]][e[1]]; 
                            }
                        }
                    }
                    count--;
                }
            } 
            
            res.push_back(count);
        }
        return res;
    }
};



