/*
https://leetcode.com/problems/excel-sheet-column-title/
*/
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res;
        
        while (columnNumber) {
            if (columnNumber <= 26) {
                res.insert(0, 1, 'A' + columnNumber - 1);
                return res;
            } else {
                int rem = columnNumber % 26;
                columnNumber /= 26;
                if (rem == 0) {
                    rem = 26;
                    columnNumber--;
                }
                res.insert(0, 1, 'A' + rem - 1);
            }
        }
        return res;
    }
};
