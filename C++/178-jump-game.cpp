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

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        vector<bool> canJmp(len);

        canJmp[len-1] = true;
        for (int i = len - 2; i >= 0; i--) {
            for (int j = 1; j <= nums[i]; j++) {
                if (canJmp[i+j]) {
                    canJmp[i] = true;
                    break;
                }
            }
        }
        return canJmp[0];
    }
};
