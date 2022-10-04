/*
https://leetcode.com/problems/rotate-string/
*/
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length())
            return false;
        if (s == goal)
            return true;
        for (int i = 1; i < s.length(); i++) {
            string part1 = s.substr(0, i);
            string part2 = s.substr(i, s.length() - i);
            if (part2 + part1 == goal)
                return true;
        }
        return false;
    }
};
