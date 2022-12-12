/*
https://leetcode.com/problems/course-schedule-ii/
*/
class Solution {
    void dfs (int numCourses, vector<vector<int>> &adj_list,
              vector<int> &visit, int a, vector<int> &res, bool &iscycle) {
        visit[a] = 1;
        for (auto &e: adj_list[a]) {
            if (visit[e] == 1) {
                iscycle = true;
                return;
            }
            if (visit[e] == 2)
                continue;      
            dfs(numCourses, adj_list, visit, e, res, iscycle);
            if (iscycle)
                return;
        }
        visit[a] = 2;
        res.push_back(a);
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<vector<int>> adj_list(numCourses);
        vector<int> visit(numCourses);
        vector<int> indegress(numCourses);

        for (auto &e : prerequisites) {
            adj_list[e[1]].push_back(e[0]);
            indegress[e[0]]++;
        }

        for (int i = 0; i < numCourses; i++) {
            if (indegress[i] == 0 && visit[i] == 0) {
                bool iscycle = false;
                dfs(numCourses, adj_list, visit, i, res, iscycle);
                if (iscycle)
                    return vector<int>();
            }
        }
        
        if (res.size() != numCourses)
            return vector<int>();

        reverse(res.begin(), res.end());
        return res;
    }
};
