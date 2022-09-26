/*
https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
*/
class Solution {
public:
    int maxDepth(string s) {
        int depth = 0, curr_depth = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                curr_depth++;
                depth = max (depth, curr_depth);
            } else if (s[i] == ')'){
                curr_depth--;
            }
        }
        return depth;
    }
};
