/*
https://leetcode.com/problems/minesweeper/
*/
class Solution {
int arr[8][2] = {{0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, 
             {0, -1}, {1, -1}, {1, 0}, {1, 1}};
    int adj_mines_revealed(vector<vector<char>>& board, int x, int y) {
        int m = board.size(), n = board[0].size();
        int count = 0, p, q;
        
        for (int i = 0; i < 8; i++) {
            p = x + arr[i][0];
            q = y + arr[i][1];
            if (p >= 0 && p < m && q >= 0 && q < n && (board[p][q] == 'X' || board[p][q] == 'M'))
                count++;
        }
        return count;
    }
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size(), n = board[0].size();
        int x = click[0], y = click[1], p, q;
        vector<vector<bool>> visit(m);
        
        for (int i = 0; i < m; i++)
            visit[i].resize(n);
        
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            visit[x][y] = true;
        }
        
        if (board[x][y] == 'E') {
            int num = adj_mines_revealed(board, x, y);
            if (num >= 1) {
                board[x][y] = num + '0';
                visit[x][y] = true;
            } else {
                board[x][y] = 'B';
                visit[x][y] = true;
                for (int i = 0; i < 8; i++) {
                    p = x + arr[i][0];
                    q = y + arr[i][1];
                    if (p >= 0 && p < m && q >= 0 && q < n &&
                        !visit[p][q] && (board[p][q] == 'E')) {
                        vector<int> v = {p, q};
                        updateBoard(board, v);    
                    }
                }                
            }
        }
        
        return board;
    }
};
