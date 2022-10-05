/*
https://leetcode.com/problems/island-perimeter/
*/
class Solution {
    int adj[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int num_row = grid.size(), num_col = grid[0].size(), count = 0;

        for (int i = 0; i < num_row; i++) {
            for (int j = 0; j < num_col; j++) {
                if (grid[i][j]) {
                    for (int m = 0; m < 4; m++) {
                        int x = i + adj[m][0];
                        int y = j + adj[m][1];
                        if (x < 0 || y < 0 || x >= num_row || y >= num_col || !grid[x][y])
                            count++;
                    }
                }
            }
        }
        return count;
    }
};
