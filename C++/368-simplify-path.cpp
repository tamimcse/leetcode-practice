/*
https://leetcode.com/problems/simplify-path/
*/
class Solution {
public:
    string simplifyPath(string path) {
        deque<string> q;
        int n = path.length();
        int start = 0, end;
        
        for (int i = 0; i < n; i++) {
            if (path[i] == '/' || i == n - 1) {
                if (path[i] == '/')
                    end = i - 1;
                else
                    end = i;
                if (start <= end) {
                    string to_insert = path.substr(start, end - start + 1);
                    if (to_insert == "..") {
                        if (!q.empty())
                            q.pop_back();
                    } else if (to_insert != ".")
                        q.push_back(to_insert);
                }
                start = i + 1;
            }
        }
        
        string res;
        while (!q.empty()) {
            res += "/";
            res += q.front();
            q.pop_front();
        }
        
        if (res == "")
            res = "/";
            
        return res;
    }
};
