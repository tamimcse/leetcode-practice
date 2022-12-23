/*
https://leetcode.com/problems/find-smallest-common-element-in-all-rows/
*/
struct Cmp {
    bool operator()(pair<int, int> &p1, pair<int, int> &p2) {
        return p1.second > p2.second;
    }
};

class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq;
        vector<int> col_idx(m);
        unordered_map<int, int> hash;

        for (int i = 0; i < m; i++) {
            pq.push(make_pair(i, mat[i][0]));
            hash[mat[i][0]]++;
        }

        while (!pq.empty()) {
            if (hash.size() == 1)
                return mat[0][col_idx[0]];
            int row = pq.top().first;
            int num = pq.top().second;
            pq.pop();
            hash[num]--;
            if (hash[num] == 0)
                hash.erase(num);
            if (col_idx[row] + 1 < n) {
                col_idx[row]++;
                pq.push(make_pair(row, mat[row][col_idx[row]]));
                hash[mat[row][col_idx[row]]]++;
            } else {
                return -1;
            } 
        }
        return -1;
    }
};
