/*
https://leetcode.com/problems/minimum-height-trees/
*/
class Solution {
    int calc_height(vector<vector<int>> adj_list, int root) {
        unordered_set<int> s;
        queue<pair<int, int>> q;
        pair<int, int> cur;
        int height = 0;
        
        q.push(make_pair(root, 0));
        s.insert(root);
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            for (auto e : adj_list[cur.first]) {
                if (s.count(e))
                    continue;
                q.push(make_pair(e, cur.second + 1));
                s.insert(e);
                height = max (height, cur.second + 1);
            }
        }
        return height;
    }
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> freq(n);
        vector<int> indices(n);
        vector<vector<int>> adj_list(n);
        vector<int> res;
        
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }
        
        for (auto &e : edges) {
            freq[e[0]]++;
            freq[e[1]]++;
            adj_list[e[0]].push_back(e[1]);
            adj_list[e[1]].push_back(e[0]);
        }
        
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return freq[a] >= freq[b];
        });
        
        
        int max_freq = indices[0];
        int max_freq_node = 0;
        for (int i = 1; i < n; i++) {
            if (freq[i] > max_freq) {
                max_freq = freq[i];
                max_freq_node = i;
            }
                
        }
        
        int h = calc_height (adj_list, indices[0]);
        res.push_back(indices[0]);
        
        for (int i = 1; i < n; i++) {
            if (calc_height (adj_list, indices[i]) == h)
                res.push_back(indices[i]);
        }
        
        return res;
    }
};
