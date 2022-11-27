/*
https://leetcode.com/problems/decode-string/
*/
class Solution {
public:
    string decodeString(string s) {
        int n = s.length();
        int sum = 0;
        
        stack<string> s1;
        stack<int> s2;
        
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                sum = sum * 10 + (s[i] - '0');
            } else if (isalpha(s[i])) {
                string s2;
                s2 += s[i];
                s1.push(s2);
            } else if (s[i] == '[') {
                s2.push (sum);
                s1.push("[");
                sum = 0;
            } else {
                string tmp;
                while (s1.top() != "[") {
                    tmp.insert(0, s1.top());
                    s1.pop();
                }
                s1.pop();
                int times = s2.top();
                s2.pop();
                for (int k = 0; k < times; k++) {
                    s1.push(tmp);
                }
            }
        }
        
        string res;
        while (!s1.empty()) {
            res.insert(0, s1.top());
            s1.pop();
        }
        
        return res;
    }
};
