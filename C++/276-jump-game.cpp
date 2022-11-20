/*
https://leetcode.com/problems/jump-game/
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), cur;
        queue<int> q;
        vector<int> visit(n);
        
        if (n == 1)
            return true;
        
        visit[0] = 1;
        q.push(0);
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            for (int i = 1; i <= nums[cur]; i++) {
                int to_jump = i + cur;
                if (to_jump == n - 1)
                    return true;
                if (to_jump < n && !visit[to_jump]) {
                    q.push(to_jump);
                    visit[to_jump] = 1;
                }
            }
        }
        return false;
    }
};
