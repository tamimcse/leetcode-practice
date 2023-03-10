/*
https://leetcode.com/problems/zigzag-conversion/

Don't use 2D array. Can you use something better?
*/
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        
        int num_col = ceil(s.length() / (float)((2 * numRows) - 2)) * (numRows - 1);
        
        vector<vector<char>> mat(numRows);
        for (int i = 0; i < numRows; i++) {
            mat[i].resize(num_col);
        }
        
        int x = 0, y = 0;
        for (auto ch : s) {
            mat[x][y] = ch;
            if (y % (numRows - 1) == 0) {
                if (x < numRows - 1) {
                    x++;
                } else {
                    x--;
                    y++;
                }  
            } else {
                x--;
                y++;
            }
        }
        
        string res;
        res.resize(s.length());
        int to_insert = 0;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < num_col; j++) {
                if (mat[i][j]) {
                    res[to_insert++] = mat[i][j];
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        
        int num_col = ceil(s.length() / (float)((2 * numRows) - 2)) * (numRows - 1);
        
        vector<string> rows(numRows);
        
        int x = 0, y = 0;
        for (auto ch : s) {
            rows[x].push_back(ch);
            if (y % (numRows - 1) == 0) {
                if (x < numRows - 1) {
                    x++;
                } else {
                    x--;
                    y++;
                }  
            } else {
                x--;
                y++;
            }
        }
        
        string res;
        for (int i = 0; i < numRows; i++) {
            res += rows[i];
        }
        return res;
    }
};

