/*
https://leetcode.com/problems/range-sum-query-2d-immutable/
*/
class NumMatrix {
    vector<vector<int>> prefix_sum;
    int m, n;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        int running_sum = 0;

        prefix_sum.resize(m);

        for (auto &e : prefix_sum)
            e.resize(n);

        for (int i = 0; i < m; i++) {
            running_sum += matrix[i][0];
            prefix_sum[i][0] = running_sum;
        }

        running_sum = 0;
        for (int i = 0; i < n; i++) {
            running_sum += matrix[0][i];
            prefix_sum[0][i] = running_sum;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                prefix_sum[i][j] = matrix[i][j] + prefix_sum[i][j-1] +
                                   prefix_sum[i-1][j] - prefix_sum[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        //left-down
        int x1 = row2, y1 = col1;
        //right-top
        int x2 = row1, y2 = col2;

        int sum = prefix_sum[row2][col2];

        if (x2 > 0) {
            sum -= prefix_sum[x2-1][y2];
        }
        if (y1 > 0) {
            sum -= prefix_sum[x1][y1-1];
        }
        if (col1 > 0 && row1 > 0) {
            sum += prefix_sum[row1-1][col1-1];
        }
        return sum;
    }
};
