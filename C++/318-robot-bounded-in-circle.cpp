/*
https://leetcode.com/problems/robot-bounded-in-circle/

Very very interesting problem. Look at the solution
*/
struct HashFunc {
    int operator()(const pair<int, int> &p) const {
        return (p.first * p.second) % 100; 
    }
};

class Solution {
    int x, y;
    int dir;
    void action (char c) {
        if (c == 'G') {
            if (dir == 0)
                y++;
            else if (dir == 1)
                x--;
            else if (dir == 2)
                y--;
            else
                x++;
        } else if (c == 'L') {
            dir = (dir + 1) % 4;
        } else {
            dir--;
            if (dir < 0)
                dir += 4;
        } 
    }
public:
    bool isRobotBounded(string instructions) {
        x = 0;
        y = 0;
        dir = 0;

        for (char c : instructions) {
            action(c);
        }
        return (x == 0 && y == 0) || dir != 0;
    }
};
