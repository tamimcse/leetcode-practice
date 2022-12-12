/*
https://leetcode.com/problems/course-schedule/
*/
class Solution {
    bool is_cycle (int numCourses, vector<vector<int>> &adj_list,
              vector<int> &visit, int a) {
        bool ret = false;
        visit[a] = 1;
        
        for (auto &e: adj_list[a]) {
            if (visit[e] == 1)
                return true;
            if (visit[e] == 2)
                continue;      
            ret = is_cycle(numCourses, adj_list, visit, e);
            if (ret)
                break;   
        }
        visit[a] = 2;
        return ret;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj_list(numCourses);
        vector<int> visit(numCourses);

        for (auto &e : prerequisites) {
            adj_list[e[1]].push_back(e[0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!visit[i]) {
                if (is_cycle(numCourses, adj_list, visit, i))
                    return false;
            }
        }
        return true;
    }
};
