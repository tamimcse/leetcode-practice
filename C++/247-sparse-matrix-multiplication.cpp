/*
https://leetcode.com/problems/sparse-matrix-multiplication/
*/
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int p = mat1.size(), q = mat1[0].size(), r = mat2[0].size();
        vector<vector<int>> res(p);
        
        for (auto &e : res)
            e.resize(r);
        
        vector<map<int, int>> m1(p);
        for (int i = 0; i < p; i++) {
            map<int, int> m;
            for (int j = 0; j < q; j++) {
                if (mat1[i][j])
                    m[j] = mat1[i][j];
            }
            m1[i] = m;
        }
        
        vector<unordered_map<int, int>> m2(r);
        for (int i = 0; i < r; i++) {
            unordered_map<int, int> m;
            for (int j = 0; j < q; j++) {
                if (mat2[j][i])
                    m[j] = mat2[j][i];
            }
            m2[i] = m;
        }
        
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < r; j++) {
                int sum = 0;
                for (auto it = m1[i].begin(); it != m1[i].end(); it++) {
                    auto itr = m2[j].find(it->first);
                    if (itr != m2[j].end()) {
                        sum += it->second * itr->second;    
                    }
                }
                res[i][j] = sum;
            }
        }
        
        return res;
    }
};
