/*
https://leetcode.com/problems/longest-absolute-file-path/
*/
class Solution {
public:
    int lengthLongestPath(string input) {
        int n = input.length(), prev_tabs, start, end, cur_tabs;
        deque<string> deq;
        int res = 0;
        
        string first;
        int i = input.find('\n');
        if (i != string::npos)
            first = input.substr(0, i);
        else
            first = input;
        deq.push_back(first);
        i++;
        start = i;
        prev_tabs = 0;
        cur_tabs = 0;
        while (i != string::npos && i < n) {
            if (input[i] == '\t') {
                cur_tabs++;
                start++;
            } else if (input[i] == '\n' || i == n - 1) {
                if (input[i] == '\n')
                    end = i - 1;
                else
                    end = i;
                string to_insert = input.substr(start, end - start + 1);
                if (cur_tabs > prev_tabs) {
                    deq.push_back(to_insert);                
                } else {
                    while (cur_tabs <= prev_tabs) {
                        deq.pop_back();
                        prev_tabs--;
                    }
                    deq.push_back(to_insert);
                }
                prev_tabs = cur_tabs;
                start = i + 1;
                cur_tabs = 0;                
                if (to_insert.find('.') != string::npos) {
                    int sum = 0;
                    for (auto &e : deq) {
                        sum += e.length();
                    }
                    sum += deq.size() - 1;
                    res = max (res, sum);
                }
            }
            i++;
        }
        return res;
    }
};
