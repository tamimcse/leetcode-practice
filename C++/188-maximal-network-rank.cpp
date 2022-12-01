/*
https://leetcode.com/problems/maximal-network-rank/
*/
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj_list(n);
        vector<vector<int>> adj_mat(n);
        int max_rank = INT_MIN;
        int rank;
        
        for (auto &e : adj_mat)
            e.resize(n);
        
        for (auto &e : roads) {
            adj_list[e[0]].push_back(e[1]);
            adj_list[e[1]].push_back(e[0]);
            adj_mat[e[0]][e[1]] = 1;
            adj_mat[e[1]][e[0]] = 1;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                rank = adj_list[i].size() + adj_list[j].size() -
                    (adj_mat[i][j] ? 1 : 0);
                max_rank = max (max_rank, rank);
            }
        }
        
        return max_rank;
    }
};
