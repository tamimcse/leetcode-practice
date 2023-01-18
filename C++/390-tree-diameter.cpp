/*
https://leetcode.com/problems/tree-diameter/

Very interesting problem!!
*/
class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adjList;
        unordered_map<int, int> indegrees;

        for (auto &v : edges) {
            adjList[v[0]].push_back(v[1]);
            adjList[v[1]].push_back(v[0]);
            indegrees[v[0]]++;
            indegrees[v[1]]++;
        }

        int n = indegrees.size();
        int diameter = 0;

        while (true) {
            vector<int> leaves;
            int live_nodes_cnt = 0;
            for (int i = 0; i < indegrees.size(); i++) {
                if (indegrees[i] == 1) {
                    leaves.push_back(i);
                }
                if (indegrees[i])
                    live_nodes_cnt++;
            }
            if (leaves.size() == 0)
                return diameter;
            else if (leaves.size() == 2 && live_nodes_cnt == 2) {
                return diameter + 1; 
            }
                
            for (auto i : leaves) {
                indegrees[i]--;
                for (auto adj : adjList[i]) {
                    if (indegrees[adj] > 0) {
                        indegrees[adj]--;
                    } 
                }
            }
            diameter += min<long> (2, leaves.size());
        }
        return diameter;
    }
};
