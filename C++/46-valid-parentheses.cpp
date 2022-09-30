/*
https://leetcode.com/problems/valid-parentheses/
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stack.push(s[i]);
            } else {
                if (stack.empty())
                    return false;
                char top = stack.top();
                stack.pop();
                if ((s[i] == ')' && top != '(') || 
                    (s[i] == '}' && top != '{') ||
                    (s[i] == ']' && top != '['))
                    return false;
            }
        }
        return stack.empty();
    }
};
