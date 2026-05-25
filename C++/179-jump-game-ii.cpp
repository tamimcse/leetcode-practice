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

class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        vector<int> canJmp(len);

        canJmp[len-1] = 1;
        for (int i = len - 2; i >= 0; i--) {
            for (int j = 1; j <= nums[i]; j++) {
                if (i + j < len && canJmp[i+j]) {
                    canJmp[i] = canJmp[i] ? min (canJmp[i], canJmp[i+j] + 1) : (canJmp[i+j] + 1);
                }
            }
        }
        return canJmp[0] - 1;   
    }
};
