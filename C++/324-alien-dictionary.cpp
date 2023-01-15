/*
https://leetcode.com/problems/alien-dictionary/

Very very very intersting problem
*/
class Solution {
    void dfs (unordered_map<char, vector<char>> &adjList,
                char start, unordered_map<char, int> &visit,
                vector<char> &res, bool &cycle) {
        visit[start] = 1;
        for (auto ch : adjList[start]) {
            if (visit[ch] == 1) {
                cycle = true;
                return;
            }
            if (visit[ch] == 0) {
                dfs (adjList, ch, visit, res, cycle);
                if (cycle)
                    return;
            }
        }
        visit[start] = 2;
        res.push_back(start);
    }
public:
    string alienOrder(vector<string>& words) {
        int n = words.size();
        unordered_map<char, vector<char>> adjList;

        for (int i = 1; i < n; i++) {
            int m = min (words[i-1].length(), words[i].length());
            for (int j = 0; j < m; j++) {
                if (words[i-1][j] != words[i][j]) {
                    adjList[words[i-1][j]].push_back(words[i][j]);
                    break;
                }
            } 
        }

        int cnt = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < words[i].length(); j++) {
                if (adjList.find(words[i][j]) == adjList.end()) {
                    adjList[words[i][j]] = vector<char>();
                    cnt++;
                    if (cnt > 1)
                        return "";
                }
            }
        }

        n = adjList.size();
        unordered_map<char, int> visit;
        vector<char> res;

        for (auto it = adjList.begin(); it != adjList.end(); it++) {
            if (visit[it->first])
                continue;
            bool cycle = false;
            cout << "starting with " << it->first << endl;
            dfs (adjList, it->first, visit, res, cycle);
            if (cycle)
                return "";
        }


        reverse(res.begin(), res.end());

        string s;
        for (int i = 0; i < res.size(); i++) {
            s += res[i];
        }
        return s;
    }
};
