/*
https://leetcode.com/problems/valid-sudoku/
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_set<int> hs;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                if (hs.count(board[i][j]))
                    return false;
                hs.insert(board[i][j]);
            }
        }
        
        for (int j = 0; j < 9; j++) {
            unordered_set<int> hs;
            for (int i = 0; i < 9; i++) {
                if (board[i][j] == '.')
                    continue;
                if (hs.count(board[i][j]))
                    return false;
                hs.insert(board[i][j]);
            }
        }
        
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                unordered_set<int> hs;
                for (int m = 0; m < 3; m++) {
                    for (int n = 0; n < 3; n++) {
                        if (board[i+m][j+n] == '.')
                            continue;
                        if (hs.count(board[i+m][j+n]))
                            return false;
                        hs.insert(board[i+m][j+n]);           
                    }
                }
            }
        }

        return true;
    }
};
