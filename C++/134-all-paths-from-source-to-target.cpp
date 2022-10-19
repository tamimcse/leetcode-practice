/*
https://leetcode.com/problems/all-paths-from-source-to-target/
*/
class Solution {
    void allPathsSourceTarget_inner(vector<vector<int>>& graph, int start, vector<int> &cur_res, 
                              vector<vector<int>> &res) {
        cur_res.push_back(start);
        
        if (start == graph.size() - 1) {
            res.push_back(cur_res);
            return;
        }
        
        for (auto e : graph[start]) {
            allPathsSourceTarget_inner(graph, e, cur_res, res);
            cur_res.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> cur_res;
        
        allPathsSourceTarget_inner(graph, 0, cur_res, res);
        return res;
    }
};
