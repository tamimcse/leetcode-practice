/*
https://leetcode.com/problems/jump-game-ii/
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), cur_idx, cur_level;
        queue<pair<int, int>> q;
        vector<int> visit(n);
        
        if (n == 1)
            return 0;
        
        visit[0] = 1;
        q.push(make_pair(0, 0));
        while (!q.empty()) {
            cur_idx = q.front().first;
            cur_level = q.front().second;
            q.pop();
            for (int i = 1; i <= nums[cur_idx]; i++) {
                int to_jump = i + cur_idx;
                int to_level = cur_level + 1;
                if (to_jump == n - 1)
                    return to_level;
                if (to_jump < n && !visit[to_jump]) {
                    q.push(make_pair(to_jump, to_level));
                    visit[to_jump] = 1;
                }
            }
        }
        return 0;
    }
};
