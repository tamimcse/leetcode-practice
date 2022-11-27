/*
https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
*/
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> stack;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            if(!stack.empty() && stack.top().first == s[i]) {
                stack.top().second++;
                if (stack.top().second == k) {
                    stack.pop();
                }
            } else {
                stack.push(make_pair(s[i], 1));
            }
        }
        
        string res;
        while (!stack.empty()) {
            auto cur = stack.top();
            stack.pop();
            for (int i = 0; i < cur.second; i++) {
                string tmp;
                tmp += cur.first;
                res.insert(0, tmp);
            }
        }
        return res;
    }
};
