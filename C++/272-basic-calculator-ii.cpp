/*
https://leetcode.com/problems/basic-calculator-ii/

It is tempting to solve this problem using recursion like reg-ex matching. But, if you look carefully, recursion will not work.
*/
class Solution {
public:
    int calculate(string s) {
        stack<int> s1;
        stack<char> s2;
        int n = s.length();
        int start, res;

        int i = 0, j = 0;
        for (; i < n; i++) {
            if (s[i] != ' ')
                s[j++] = s[i];
        }
        s.erase(j);
        n = s.length();

        i = 0;
        while (i < n && isdigit(s[i]))
            i++;
        s1.push(atoi(s.substr(0, i).c_str()));

        while (i < n) {
            s2.push(s[i++]);
            start = i;
            while (i < n && isdigit(s[i]))
                i++;
            s1.push(atoi(s.substr(start, i - start).c_str()));
            if (s2.top() == '*' || s2.top() == '/') {
                int b = s1.top();
                s1.pop();
                int a = s1.top();
                s1.pop();
                res = s2.top() == '*' ? a * b : a / b;
                s1.push(res);
                s2.pop();
            }
        }
        stack<int> s3;
        stack<char> s4;
        while (!s1.empty()) {
            s3.push(s1.top());
            s1.pop();
        }
        while (!s2.empty()) {
            s4.push(s2.top());
            s2.pop();
        }
        while (!s4.empty()) {
            char op =  s4.top();
            s4.pop();
            int a = s3.top();
            s3.pop();
            int b = s3.top();
            s3.pop();
            res = op == '+' ? a + b : a - b;
            s3.push(res);
        }
        return s3.top();
    }
};
