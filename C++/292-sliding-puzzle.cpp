/*
https://leetcode.com/problems/sliding-puzzle/
*/
struct BoardConfig{
    vector<vector<int>> board;
    int zero_x;
    int zero_y;
    BoardConfig() {
        
    }
    BoardConfig (vector<vector<int>> b, int x, int y) {
        board = b;
        zero_x = x;
        zero_y = y;
    }
};

struct HashFunc {
    int operator()(const vector<vector<int>> p) const {
        int sum = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                sum = sum * 10 + p[i][j];
            }
        }

        return sum% 100;
    }
};

class Solution {
    int adj[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    bool isEnd(vector<vector<int>>& board) {
        return board[0][0] == 1 && board[0][1] == 2 && board[0][2] == 3 &&
               board[1][0] == 4 && board[1][1] == 5 && board[1][2] == 0;
    }
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        queue<pair<BoardConfig, int>> q;
        unordered_set<vector<vector<int>>, HashFunc> visit;
        BoardConfig cur_board;
        int cur_level;
        int zero_x, zero_y;

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 0) {
                    zero_x = i;
                    zero_y = j;
                    break;
                }
            }
        }

        q.push(make_pair(BoardConfig(board, zero_x, zero_y), 0));
        visit.insert(board);
        while (!q.empty()) {
            cur_board = q.front().first;
            cur_level = q.front().second;
            if (isEnd(cur_board.board))
                return cur_level;
            q.pop();    
            for (int k = 0; k < 4; k++) {
                int adj_x = cur_board.zero_x + adj[k][0];
                int adj_y = cur_board.zero_y + adj[k][1];
                if (adj_x >= 0 && adj_x < 2 && adj_y >= 0 && adj_y < 3) {
                    swap(cur_board.board[cur_board.zero_x][cur_board.zero_y],
                        cur_board.board[adj_x][adj_y]);
                    if (visit.count(cur_board.board) == 0) {
                        visit.insert(cur_board.board);
                        q.push(make_pair(BoardConfig(cur_board.board, adj_x, adj_y),
                                cur_level + 1));
                    }
                    swap(cur_board.board[cur_board.zero_x][cur_board.zero_y],
                        cur_board.board[adj_x][adj_y]);    
                }
            }                  
        }
        return -1;
    }
};
