/*
https://leetcode.com/problems/evaluate-reverse-polish-notation/
*/
class Solution {
    long eval (char ch, long a, long b) {
        switch(ch) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
        }
        return 0;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        
        for (auto &e : tokens) {
            if (isdigit(e[e.length() - 1])) {
                s.push(atol(e.c_str()));
            } else {
                long a = s.top();
                s.pop();
                long b = s.top();
                s.pop();
                long res = eval (e[0], b, a);
                s.push(res);
            }
        }
        return s.top();
    }
};
