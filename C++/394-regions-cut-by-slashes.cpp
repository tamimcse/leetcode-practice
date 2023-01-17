/*
https://leetcode.com/problems/regions-cut-by-slashes/description/

Very interesting problem!!!!!!!
*/
class Solution {
int n;
unordered_map<int, vector<int>> adjList;
    void add_nodes_in_cell (vector<string>& grid, int x, int y) {
        if (grid[x][y] == ' ') {
            adjList[(x * n + y) * 4 + 0].push_back((x * n + y) * 4 + 1);
            adjList[(x * n + y) * 4 + 1].push_back((x * n + y) * 4 + 0);
            adjList[(x * n + y) * 4 + 1].push_back((x * n + y) * 4 + 2);
            adjList[(x * n + y) * 4 + 2].push_back((x * n + y) * 4 + 1);
            adjList[(x * n + y) * 4 + 2].push_back((x * n + y) * 4 + 3);
            adjList[(x * n + y) * 4 + 3].push_back((x * n + y) * 4 + 2);
        } else if (grid[x][y] == '/') {
            adjList[(x * n + y) * 4 + 0].push_back((x * n + y) * 4 + 1);
            adjList[(x * n + y) * 4 + 1].push_back((x * n + y) * 4 + 0);
            adjList[(x * n + y) * 4 + 2].push_back((x * n + y) * 4 + 3);
            adjList[(x * n + y) * 4 + 3].push_back((x * n + y) * 4 + 2);
        } else {
            adjList[(x * n + y) * 4 + 1].push_back((x * n + y) * 4 + 2);
            adjList[(x * n + y) * 4 + 2].push_back((x * n + y) * 4 + 1);
            adjList[(x * n + y) * 4 + 0].push_back((x * n + y) * 4 + 3);
            adjList[(x * n + y) * 4 + 3].push_back((x * n + y) * 4 + 0);
        }
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        n = grid.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                add_nodes_in_cell (grid, i, j);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i >= 1) {
                    adjList[(i * n + j) * 4 + 1].push_back(((i-1) * n + j) * 4 + 3);
                    adjList[((i-1) * n + j) * 4 + 3].push_back((i * n + j) * 4 + 1);
                }
                if (j >= 1) {
                    adjList[(i * n + j) * 4 + 0].push_back((i * n + (j - 1)) * 4 + 2);
                    adjList[(i * n + (j - 1)) * 4 + 2].push_back((i * n + j) * 4 + 0);
                }
            }
        }

        vector<bool> visit(4 * n * n);
        int count = 0;
        for (int i = 0; i < 4 * n * n; i++) {
            if (visit[i])
                continue;
            count++;
            queue<int> q;

            q.push(i);
            visit[i] = true;
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                for (auto adj : adjList[cur]) {
                    if (!visit[adj]) {
                        visit[adj] = true;
                        q.push(adj);
                    }
                }
            }
            cout << endl;
        }
        return count;
    }
};
