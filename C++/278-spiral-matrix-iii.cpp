/*
https://leetcode.com/problems/spiral-matrix-iii/
*/
class Solution {
    void next_point(int &rStart, int &cStart, int dir) {
        switch (dir) {
            case 0:
                 cStart++;
                 break;
            case 1:
                rStart++;
                break;
            case 2:
                cStart--;
                break;
            case 3: 
                rStart--;
                break;
        }
    }
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> res;
        int moves = 1;
        unordered_set<int> us;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                us.insert(i * cols + j);
            }
        }

        res.push_back({rStart, cStart});
        us.erase(rStart * cols + cStart);
        int dir = 0;
        while (us.size()) {
            for (int i = 0; i < moves; i++) {
                next_point (rStart, cStart, dir);
                if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                    res.push_back({rStart, cStart});
                    us.erase(rStart * cols + cStart);
                }
            }
            dir = (dir + 1) % 4;
            for (int i = 0; i < moves; i++) {
                next_point (rStart, cStart, dir);
                if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                    res.push_back({rStart, cStart});
                    us.erase(rStart * cols + cStart);
                }
            }
            dir = (dir + 1) % 4;
            moves++;
        }
        return res;
    }
};
