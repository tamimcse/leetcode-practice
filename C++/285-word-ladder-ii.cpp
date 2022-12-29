/*
https://leetcode.com/problems/word-ladder-ii

very interesting problem!!!
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

    void add_edges (string dest, vector<string>& wordList,
                    unordered_set<string> &visit,
                    unordered_map<string, vector<string>> &adj_list) {
        for (auto &e : wordList) {
            if (e != dest && visit.count(e) == 0 && is_adjacent(e, dest))
                adj_list[e].push_back(dest);
        }
    }

    void dfs (string cur, unordered_map<string, vector<string>> &adj_list,
              vector<string> &path, vector<vector<string>> &res, string &end) {
        path.push_back(cur);
        if (cur == end) {
            vector<string> cur_path = path;
            reverse(cur_path.begin(), cur_path.end());
            res.push_back(cur_path);
            path.pop_back();
            return;
        }
        for (auto &e : adj_list[cur]) {
            dfs (e, adj_list, path, res, end);
        }
        path.pop_back();
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> adj_list;
        queue<string> q;
        unordered_set<string> visit;
        string cur;

        q.push(beginWord);
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            visit.insert(cur);
            //cout << cur << " ";
            for (auto &e : wordList) {
                if (visit.count(e) || !is_adjacent(e, cur))
                    continue;    
                adj_list[e].push_back(cur);
                cout << "Adding edge between " << e << " and " << cur << endl;
                q.push(e);
                if (e == endWord) {
                    goto backtrack;
                }
            }
        }

backtrack:

        while (!q.empty()) {
            cur = q.front();
            q.pop();
            if (visit.count(cur) == 0 && is_adjacent(endWord, cur)) {
                adj_list[endWord].push_back(cur);
                visit.insert(cur);
                cout << "Adding edge between " << endWord << " and " << cur << endl;
            }
        }
        
        vector<vector<string>> res;
        vector<string> path;

        dfs (endWord, adj_list, path, res, beginWord);
        return res;
    }
};
