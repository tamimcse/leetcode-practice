/*
https://leetcode.com/problems/robot-bounded-in-circle/

Fascinating problem!!!!!!!!!!!!!!!!!!! Take a look at the solution if you don't remember it.
*/

class Solution {
public:
    bool isRobotBounded(string instructions) {
      int x = 0, y = 0, dir = 0;
      for (auto ch : instructions) {
        if (ch == 'G') {
          if (!dir)
            y++;
          else if (dir == 1)
            x++;
          else if (dir == 2)
            y--;
          else
            x--;
      } else if (ch == 'R') {
        dir = (dir + 1) % 4;
      } else {
        dir--;
        if (dir == -1)
          dir = 3;
      }
    }
    
    return (x == 0 && y == 0) || dir;
  }
};
