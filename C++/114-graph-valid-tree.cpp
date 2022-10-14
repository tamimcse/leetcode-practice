/*
https://leetcode.com/problems/graph-valid-tree/
*/
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj_list;
        
        for (auto &e : edges) {
            adj_list[e[0]].push_back(e[1]);
            adj_list[e[1]].push_back(e[0]);
        }

        stack<int> s;
        unordered_map<int, bool> visit;
        int count = 0;
        
        s.push(0);
        while (!s.empty()) {
            int cur = s.top();
            s.pop();
            
            if (visit.find(cur) != visit.end())
                return false;
            visit[cur] = true;
            count++;
            for (auto e : adj_list[cur]) {
                if (visit.find(e) != visit.end())
                    continue;
                s.push(e);
            }
        }
        return count == n;
    }
};
