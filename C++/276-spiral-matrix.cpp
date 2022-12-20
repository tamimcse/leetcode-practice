/*
https://leetcode.com/problems/spiral-matrix/
*/
class Solution {

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size();
        int dir = 0;
        vector<vector<bool>> visit(m);

        for (int i = 0; i < m; i++)
            visit[i].resize(n);

        int i = 0, j = 0;
        while (true) {
            res.push_back(matrix[i][j]);
            visit[i][j] = true;
            if (dir == 0) {
                if (j + 1 < n && !visit[i][j+1]) {
                    j++;
                } else if (i + 1 < m && !visit[i+1][j]) {
                    i++;
                    dir = 1;
                } else {
                    break;
                }
            } else if (dir == 1) {
                if (i + 1 < m && !visit[i+1][j]) {
                    i++;
                } else if (j - 1 >= 0 && !visit[i][j-1]) {
                    j--;
                    dir = 2;
                } else {
                    break;
                }
            } else if (dir == 2) {
                if (j - 1 >= 0 && !visit[i][j-1]) {
                    j--;
                } else if (i - 1 >= 0 && !visit[i-1][j]) {
                    i--;
                    dir = 3;
                } else {
                    break;
                }
            } else {
                if (i - 1 >= 0 && !visit[i-1][j]) {
                    i--;
                } else if (j + 1 < n && !visit[i][j+1]) {
                    j++;
                    dir = 0;
                } else {
                    break;
                }
            }
        }

        return res;
    }
};
