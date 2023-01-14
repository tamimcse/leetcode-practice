/*
https://leetcode.com/problems/is-graph-bipartite/

Very very very interesting problem!!!!!
*/
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<int> q;
        vector<int> color(n);

        for (int i = 0; i < n; i++) {
            if (color[i])
                continue;
            q.push(i);
            color[i] = 1;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int adj : graph[node]) {
                    if (color[adj] != 0 && 
                        color[adj] == color[node])
                        return false;
                    if (color[adj] == 0) {
                        q.push(adj);
                        color[adj] = color[node] == 1 ? 2 : 1;
                    }
                }
            }
        }
        return true;
    }
};
