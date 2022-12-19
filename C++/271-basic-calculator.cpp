/*
https://leetcode.com/problems/basic-calculator/
*/
class Solution {
    int calculate (stack<string> &s1, stack<char> &s2) {
        while (!s2.empty()) {
            char op =  s2.top();
            s2.pop();
            int a = atoi(s1.top().c_str());
            s1.pop();
            int b = atoi(s1.top().c_str());
            s1.pop();
            int res = op == '+' ? a + b : a - b;
            s1.push(to_string(res));
        }
        return atoi(s1.top().c_str());
    }
public:
    int calculate(string s) {
        stack<string> s1;
        stack<char> s2;
        int n = s.length();
        int start;
        int ret;

        int i = 0, j = 0;
        for (; i < n; i++) {
            if (s[i] != ' ')
                s[j++] = s[i];
        }
        s.erase(j);
        n = s.length();

        i = 0;
        for (;i < n; i++) {
            if (s[i] == '(') {
                s1.push("(");
            } else if (s[i] == '-' && (i + 1 < n) && s[i+1] == '(' && 
                        (i == 0 || s[i-1] == '(')) {
                s1.push("N");
            } else if (isdigit(s[i]) || (s[i] == '-' && (i == 0 || s[i-1] == '('))) {
                start = i;
                while (i + 1 < n && isdigit(s[i+1]))
                    i++;
                s1.push(s.substr(start, i - start + 1));
            } else if (s[i] == '+' || s[i] == '-') {
                s2.push(s[i]);
            } else if (s[i] == ')') {
                stack<string> s3;
                stack<char> s4;
                s3.push(s1.top());
                s1.pop();
                while (s1.top() != "(") {
                    s3.push(s1.top());
                    s1.pop();
                    s4.push(s2.top());
                    s2.pop();
                }
                s1.pop();
                ret = calculate(s3, s4);
                if (!s1.empty() && s1.top() == "N") {
                    ret = -ret;
                    s1.pop();
                } 
                s1.push(to_string(ret));
            }
        }
        stack<string> s3;
        stack<char> s4;
        while (!s1.empty()) {
            s3.push(s1.top());
            s1.pop();
        }
        while (!s2.empty()) {
            s4.push(s2.top());
            s2.pop();
        }
        return calculate(s3, s4);
    }
};
