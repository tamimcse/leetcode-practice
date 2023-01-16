/*
https://leetcode.com/problems/satisfiability-of-equality-equations/description/

Very very very very interesting problem!!!!!
*/

class Solution {
    
    bool isSameCC(char x, char y, unordered_map<char, vector<char>> &adjList) {
        queue<char> q;
        unordered_set<char> visit;

        q.push(x);
        visit.insert(x);
        while (!q.empty()) {
            char cur = q.front();
            q.pop();

            if (cur == y)
                return true;

            for (auto ch : adjList[cur]) {
                if (visit.count(ch) == 0) {
                    visit.insert(ch);
                    q.push(ch);
                }
            }
        }
        return false;
    }
public:
    bool equationsPossible(vector<string>& equations) {
        unordered_map<char, vector<char>> adjList;

        for (auto s : equations) {
            if (s[1] == '=') {
                adjList[s[0]].push_back(s[3]);
                adjList[s[3]].push_back(s[0]);
            }
        }

        for (auto s : equations) {
            if (s[1] == '!') {
                if (isSameCC (s[0], s[3], adjList))
                    return false;
            }
        }
        return true;
    }
};
