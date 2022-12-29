/*
https://leetcode.com/problems/word-ladder-ii

very interesting problem!!!
*/


/*****This solution gets TLE*************************************************/

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
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        int start = -1, end;
        int max_depth = -1;

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
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (is_adjacent (wordList[i], wordList[j])) {
                    adj_list[i].push_back(j);
                    adj_list[j].push_back(i);
                }
            }
        }

        queue<pair<int, int>> q;
        vector<int> visit(n);
        queue<vector<int>> res_q;

        q.push(make_pair(start, 1));
        res_q.push({start});
        while (!q.empty()) {
            int cur_word = q.front().first;
            int level = q.front().second;
            vector<int> cur_vec = res_q.front();
            q.pop();
            res_q.pop();
            visit[cur_word] = true;
            for (int i : adj_list[cur_word]) {
                if (max_depth > 0 && level > max_depth)
                    return res;
                if (visit[i])
                    continue;    

                if (i == end) {
                    vector<string> tmp;
                    for (int e : cur_vec) {
                        tmp.push_back(wordList[e]);
                    }
                    tmp.push_back(endWord);
                    res.push_back(tmp);
                    max_depth = level;
                    continue;
                }
                q.push(make_pair(i, level + 1));
                vector<int> tmp = cur_vec;
                tmp.push_back(i);
                res_q.push(tmp);
            }
        }

        return  res;
    }
};


/**********This also gets TLE******************/
class Solution {
    unordered_map<string, vector<string>> adj_list;
    vector<string> path;

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
    vector<string> findNeighbors(vector<string> &list, unordered_set<string> &visit,
                                string node) {
        vector<string> res;
        for (int i = 0; i < list.size(); i++) {
            if (visit.count(list[i]) == 0 && is_adjacent(list[i], node))
                res.push_back(list[i]);
        }
        return res;
    }

    void dfs (string cur, string end, vector<vector<string>> &res) {
        cout << cur << " ";
        path.push_back(cur);
        if (cur == end) {
            reverse(path.begin(), path.end());
            res.push_back(path);
            reverse(path.begin(), path.end());
            path.pop_back();
            return;
        }

        for (auto &e : adj_list[cur]) {
            dfs (e, end, res);
        }
        path.pop_back();
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), beginWord) == wordList.end())
            wordList.push_back(beginWord);
        queue<pair<string, int>> q;
        string cur_str;
        int cur_lev;
        unordered_set<string> visit;
        
        int max_depth = -1;
        q.push(make_pair(beginWord, 1));
        while (!q.empty()) {
            cur_str = q.front().first;
            cur_lev = q.front().second;
            q.pop();
            if (visit.count(cur_str))
                continue;
            vector<string> neigh = findNeighbors (wordList, visit, cur_str);
            for (auto e : neigh)
                adj_list[e].push_back(cur_str); 
            visit.insert(cur_str);
            cout << cur_str << endl;
            bool found_end = false;
            for (auto &e : neigh) {
                if (e == endWord) {
                    found_end = false;
                    break;
                }
                cout << "Pushing " << e << endl;        
                q.push(make_pair(e, cur_lev + 1));
            }
            if (found_end)
                break;
        }

        vector<vector<string>> res;
        
        cout << "DFS = ";

        dfs (endWord, beginWord, res);
        return  res;
    }
};
