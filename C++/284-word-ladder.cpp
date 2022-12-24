/*
https://leetcode.com/problems/word-ladder/
*/
class Solution {
    bool is_adjacent (string &s1, string &s2) {
        int n = s1.length();
        int count = 0;

        if (s1 == s2)
            return false;

        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                count++;
                if (count > 1)
                    return false;
            }
        }
        return true;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int start = -1, end;

        for (int i = 0; i < wordList.size(); i++) {
            if (wordList[i] == beginWord)
                start = i;
            if (wordList[i] == endWord)
                end = i;
        }
        if (start == -1) {
            wordList.push_back(beginWord);
            start = wordList.size() - 1;
        }

        int n = wordList.size();

        vector<vector<int>> adj_list (n);
        vector<bool> visit(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (is_adjacent (wordList[i], wordList[j])) {
                    adj_list[i].push_back(j);
                    adj_list[j].push_back(i);
                }
            }
        }

        queue<pair<int, int>> q;

        q.push(make_pair(start, 1));
        visit[start] = true;
        while (!q.empty()) {
            int cur_word = q.front().first;
            int level = q.front().second;
            q.pop();
            if (cur_word == end)
                return level;
            for (int i : adj_list[cur_word]) {
                if (!visit[i]) {
                    q.push(make_pair(i, level + 1));
                    visit[i] = true;
                }
            }
        }

        return  0;
    }
};
