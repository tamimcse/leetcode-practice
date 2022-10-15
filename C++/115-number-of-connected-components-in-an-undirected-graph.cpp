/*
https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/
*/
class Solution {
    void dfs(unordered_map<int, vector<int>> &adj_list, int start, int *visited) {
        stack<int> s;
        int cur;
        
        s.push(start);
        while (!s.empty()) {
            cur = s.top();
            s.pop();
            if (visited[cur])
                continue;
            visited[cur] = 1;
            for (auto &e : adj_list[cur]) {
                if (!visited[e])
                    s.push(e);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj_list (n);
        int *visited = new int[n]();
        int count = 0;
        
        for (auto &e : edges) {
            adj_list[e[0]].push_back(e[1]);
            adj_list[e[1]].push_back(e[0]);
        }
        
        for (int i = 0; i < n; i++) {
            if (visited[i])
                continue;
            dfs(adj_list, i, visited);
            count++;
        }
        return count;
    }
};
