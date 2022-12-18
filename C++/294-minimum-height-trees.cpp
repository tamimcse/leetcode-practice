/*
https://leetcode.com/problems/minimum-height-trees/
*/

/*******This gets TLE******************************/
class Solution {
    int height(vector<vector<int>>& adj_list, int start, int prev) {
        int h = 0;

        for (auto e : adj_list[start]) {
            if (e == prev)
                continue;
            h = max (h, 1 + height(adj_list, e, start));
        }
        return h;
    }
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj_list(n);
        vector<int> tree_height(n);
        vector<int> res;

        for (auto &e : edges) {
            adj_list[e[0]].push_back(e[1]);
            adj_list[e[1]].push_back(e[0]);
        }

        for (int i = 0; i < n; i++) {
            tree_height[i] = height(adj_list, i, -1);
        }

        int min_h = tree_height[0];
        for (int i = 1; i < n; i++) {
            min_h = min (min_h, tree_height[i]);
        }

        for (int i = 0; i < n; i++) {
            if (tree_height[i] == min_h) {
                res.push_back(i);
            }
        }
        return res;
    }
};


/*******This solution works ************/


class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> adj_list(n);
        vector<int> res;

        for (auto &e : edges) {
            adj_list[e[0]].insert(e[1]);
            adj_list[e[1]].insert(e[0]);
        }

        unordered_set<int> nodes;
        for (int i = 0; i < n; i++) {
            nodes.insert(i);
        }
        while (nodes.size() > 2) {
            unordered_set<int> us;
            int j;
            for (auto it = nodes.begin(); it != nodes.end();) {
                int i = *it;
                if (us.count(i)) {
                    it++;
                    continue;
                }
                if (adj_list[i].size() == 1) {
                    j = *adj_list[i].begin();
                    adj_list[j].erase(i);
                    adj_list[i].erase(j);
                    us.insert(i);
                    us.insert(j);
                    it = nodes.erase(it);
                } else {
                    it++;
                }
            }
        }

        for (auto e : nodes) {
            res.push_back(e);
        }
        return res;
    }
};
