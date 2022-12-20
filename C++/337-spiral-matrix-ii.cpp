/*
https://leetcode.com/problems/spiral-matrix-ii/
*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int dir = 0, num = 1;
        vector<vector<int>> matrix(n);
        vector<vector<bool>> visit(n);

        for (int i = 0; i < n; i++) {
            visit[i].resize(n);
            matrix[i].resize(n);
        }
            
        int i = 0, j = 0;
        while (true) {
            matrix[i][j] = num++;
            visit[i][j] = true;
            if (dir == 0) {
                if (j + 1 < n && !visit[i][j+1]) {
                    j++;
                } else if (i + 1 < n && !visit[i+1][j]) {
                    i++;
                    dir = 1;
                } else {
                    break;
                }
            } else if (dir == 1) {
                if (i + 1 < n && !visit[i+1][j]) {
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
        return matrix;        
    }
};
