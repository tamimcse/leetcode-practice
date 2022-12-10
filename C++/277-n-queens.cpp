/*
https://leetcode.com/problems/n-queens/
*/
class Solution {
    bool valid(vector<string> &board, int x, int y) {
        int n = board.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'Q') {
                    if (i == x || j == y || abs(i - x) == abs(j - y))
                        return false;
                }
            }
        }
        return true;
    }
    void solveNQueens(int n, vector<string> &board, int row, vector<vector<string>> &res) {
        for (int i = 0; i < n; i++) {
            if (valid(board, row, i)) {
                board[row][i] = 'Q';
                if (row == n - 1)
                    res.push_back(board);    
                else
                    solveNQueens (n, board, row + 1, res);
                board[row][i] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n);

        for (auto &e : board) {
            e.resize(n);
            for (int i = 0; i < n; i++)
                e[i] = '.';
        }

        if (n == 1) {
            res.push_back({"Q"});
            return res;
        }

        for (int i = 0; i < n; i++) {
            board[0][i] = 'Q';
            solveNQueens (n, board, 1, res);
            board[0][i] = '.';
        }
        return res;
    }
};
