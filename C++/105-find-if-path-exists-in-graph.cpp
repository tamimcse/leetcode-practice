/*
https://leetcode.com/problems/find-if-path-exists-in-graph/
*/
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj_list(n);
        int *hash = new int[n];
        queue<int> q;
        int cur;
        
        for (int i = 0; i < edges.size(); i++) {
            adj_list[edges[i][0]].push_back(edges[i][1]);
            adj_list[edges[i][1]].push_back(edges[i][0]);
        }
        
        for (int i = 0; i < n; i++)
            hash[i] = 0;
        
        q.push(source);
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            if (cur == destination)
                return true;
            hash[cur] = 1;
            for (int i = 0; i < adj_list[cur].size(); i++) {
                if (!hash[adj_list[cur][i]])
                    q.push(adj_list[cur][i]);
            }
        }
        return false;
    }
};
