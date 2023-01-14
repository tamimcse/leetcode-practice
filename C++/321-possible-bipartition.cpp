/*
https://leetcode.com/problems/possible-bipartition/description/
*/
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adjList(n+1);

        for (auto &e : dislikes) {
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }

        queue<int> q;
        vector<int> color(n+1);

        for (int i = 1; i <= n; i++) {
            if (color[i])
                continue;
            q.push(i);
            color[i] = 1;
            while (!q.empty()) {
                int person = q.front();
                q.pop();

                for (auto dislike : adjList[person]) {
                    if (color[dislike] != 0 &&
                        color[person] == color[dislike])
                        return false;
                    if (color[dislike] == 0) {
                        q.push(dislike);
                        color[dislike] = color[person] == 1 ? 2 : 1;
                    } 
                }
            }
        }
        return true;
    }
};
