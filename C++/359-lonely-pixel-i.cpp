/*
https://leetcode.com/problems/lonely-pixel-i/
*/
class Solution {
    
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int m = picture.size(), n = picture[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (picture[i][j] == 'B') {
                    for (int p = 0; p < m; p++) {
                        if (i != p && 
                            (picture[p][j] == 'B' || picture[p][j] == 'A')) {
                            picture[i][j] = 'A';
                            picture[p][j] = 'A';
                        }
                    }
                    for (int p = 0; p < n; p++) {
                        if (j != p && (picture[i][p] == 'B' || picture[i][p] == 'A')) {
                            picture[i][j] = 'A';
                            picture[i][p] = 'A';
                        }
                    }
                }
            }
        }
        
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (picture[i][j] == 'B') {
                    count++;
                }
            }
        }
        return count;
    }
};
