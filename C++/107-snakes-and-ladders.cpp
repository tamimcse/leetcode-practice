/*
https://leetcode.com/problems/snakes-and-ladders/
*/
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        vector<int> jump;
        jump.resize(board.size() * board.size() + 1);
        queue<pair<int, int>> q;
        pair<int, int> cur;
        unordered_map<int, bool> hash;

        bool right = true;
        for (int i = board.size() - 1; i >= 0; i--) {
            for (int j = 0; j < board.size(); j++) {
                if (right)
                    jump[(board.size() - 1 - i) * board.size() + j + 1] = board[i][j];
                else
                    jump[(board.size() - 1 - i) * board.size() + (board.size() - 1- j) + 1] = board[i][j];
            }
            right = !right;
        }
        q.push(make_pair(1, 0));
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            if (hash.find(cur.first) != hash.end())
                continue;
            hash[cur.first] = true;
            if (cur.first == (board.size() * board.size()))
                return cur.second;
            for (int j = 1; j <= 6; j++) {
                if (cur.first + j > (board.size() * board.size()))
                    continue;
                if (jump[cur.first + j] == -1)
                    q.push(make_pair(cur.first + j, cur.second + 1));
                else
                    q.push(make_pair(jump[cur.first + j], cur.second + 1));
            }
        }
        return -1;
    }
};
