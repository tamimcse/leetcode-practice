/*
https://leetcode.com/problems/game-of-life/

Implement using O(1) space
*/
class Solution {
    int arr[8][2] = {{0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, 
                     {0, -1}, {1, -1}, {1, 0}, {1, 1}};
    
    bool isValidCor(vector<vector<int>>& board, int x, int y) {
        int m = board.size(), n = board[0].size();
        
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    
    int num_live_neighbor(vector<vector<int>>& board, int x, int y) {
        int m = board.size(), n = board[0].size();
        int row, col;
        int count = 0;
        
        for (int i = 0; i < 8; i++) {
            row = x + arr[i][0];
            col = y + arr[i][1];
            if (isValidCor(board, row, col) && 
                (board[row][col] == 1 || board[row][col] == 2))
                count++;
        }
        return count;
    }

public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j]) {
                    int live_neigh = num_live_neighbor (board, i, j);
                    if (live_neigh < 2 || live_neigh > 3)
                        board[i][j] = 2;
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!board[i][j]) {
                    int live_neigh = num_live_neighbor (board, i, j);
                    if (live_neigh == 3)
                        board[i][j] = 3;
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 2)
                    board[i][j] = 0;
                else if (board[i][j] == 3)
                    board[i][j] = 1;
            }
        }
    }
};
