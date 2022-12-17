/*
https://leetcode.com/problems/clumsy-factorial/

Very interesting problem!!!
*/
class Solution {
public:
    int clumsy(int n) {
        stack<int> s1, s2;
        queue<char> q;
        int res, a, b;

        if (n == 1)
            return n;

        s1.push(n);
        for (int i = n-1, turn = 0; i >= 1; i--, turn = (turn + 1) % 4) {
            if (turn == 0) {
                res = s1.top() * i;
                s1.pop();
                s1.push(res);
            } else if (turn == 1) {
                res = s1.top() / i;
                s1.pop();
                s1.push(res);
            } else if (turn == 2) {
                s1.push(i);
                q.push('+');
            } else {
                s1.push(i);
                q.push('-');
            }
        }

        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        while (!q.empty()) {
            a = s2.top();
            s2.pop();
            b = s2.top();
            s2.pop();
            res = (q.front() == '+') ? a + b : a - b;
            q.pop();
            s2.push(res);
        }

        return s2.top();
    }
};
