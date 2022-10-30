/*
https://leetcode.com/problems/word-search/
*/
class Solution {
    int arr[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    bool dfs(vector<vector<char>>& board, int x, int y, string word, int idx,
             vector<vector<bool>> &visit) {
        if (idx == word.length() - 1)
            return true;
        int m = board.size(), n = board[0].size(), p, q;
        
        visit[x][y] = true;
        
        for (int i = 0; i < 4; i++) {
            p = x + arr[i][0];
            q = y + arr[i][1];
            if (p >= 0 && p < m && q >= 0 && q < n && !visit[p][q] &&
                word[idx + 1] == board[p][q]) {
                bool res = dfs(board, p, q, word, idx + 1, visit);
                if (res)
                    return true;
            }
            
        }
        visit[x][y] = false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visit(m);
        
        for (int i = 0; i < m; i++)
            visit[i].resize(n);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, i, j, word, 0, visit))
                        return true;
                }
            }
        }
        return false;
    }
};
