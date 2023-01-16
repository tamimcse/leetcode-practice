/*
https://leetcode.com/problems/longest-string-chain/

Interesting problem!
*/
class Solution {
    int n;
    unordered_map<string, vector<string>> adjList;

    bool isPredeccessor(string s1, string s2) {
        int n = s2.length();
        bool found = false;

        for (int i = 0, j = 0; i < n; i++) {
            if (s2[i] == s1[j]) {
                j++;
            } else {
                if (found)
                    return false;
                found = true;
            }
        }
        return true;
    }
    int dfs (string &start) {
        int res = 0;

        stack<string> s;
        unordered_map<string, int> visit;
        s.push(start);
        int depth = 0;
        while (!s.empty()) {
            string cur = s.top();
            if (visit[cur] == 2) {
                res = max(res, depth);
                depth--;
                s.pop();
                continue;
            }
            for (auto str : adjList[cur]) {
                if (visit[str] == 2)
                    continue;
                visit[str] = 1;
                s.push(str);
            }
            depth++;
            visit[cur] = 2;
        }
        return res;
    }
public:
    int longestStrChain(vector<string>& words) {
        n = words.size();
        unordered_set<string> not_indegree_zero;

        sort (words.begin(), words.end(), [](string &s1, string &s2) {
            return s1.length() < s2.length(); 
        });

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (words[i].length() == words[j].length())
                    continue;
                if (words[i].length() + 1 < words[j].length())
                    break;
                if (isPredeccessor(words[i], words[j])) {
                    adjList[words[i]].push_back(words[j]);
                    not_indegree_zero.insert(words[j]);
                }
            }
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            if (not_indegree_zero.count(words[i]))
                continue;
            int len = dfs (words[i]);
            res = max (res, len);
        }
        return res;
    }
};
