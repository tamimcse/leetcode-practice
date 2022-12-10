/*
https://leetcode.com/problems/sudoku-solver/

Interesting problem!
*/
class Solution {
    void solveSudoku(vector<vector<char>>& board, unordered_set<int> row_set[],
                unordered_set<int> col_set[], unordered_set<int> subbox_set[],
                int num_cnt, bool &done) {                    
        if (num_cnt == 81) {
            done = true;
            return;
        }            
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    int subbox_idx = (i / 3) * 3 + (j / 3);
                    for (int k = 1; k <= 9; k++) {
                        if (row_set[i].count(k) || col_set[j].count(k) ||
                            subbox_set[subbox_idx].count(k))
                            continue;
                        row_set[i].insert(k);
                        col_set[j].insert(k);
                        subbox_set[subbox_idx].insert(k);
                        board[i][j] = k + '0';
                        solveSudoku(board, row_set, col_set, subbox_set, num_cnt + 1, done);
                        if (done)
                            return;
                        row_set[i].erase(k);
                        col_set[j].erase(k);
                        subbox_set[subbox_idx].erase(k);
                        board[i][j] = '.';
                    }
                    return;
                }
            }
        }
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        unordered_set<int> row_set[9];
        unordered_set<int> col_set[9];
        unordered_set<int> subbox_set[9];
        int num;
        int num_count = 0;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    num = board[i][j] - '0';            
                    row_set[i].insert(num);
                    col_set[j].insert(num);
                    int subbox_idx = (i / 3) * 3 + (j / 3);
                    subbox_set[subbox_idx].insert(num);
                    num_count++;
                }
            }
        }
        bool found = false;
        solveSudoku (board, row_set, col_set, subbox_set, num_count, found);
    }
};
