/*
https://leetcode.com/problems/largest-number/
*/
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort (nums.begin(), nums.end(), [](int a, int b) {
            stack<int> s1;
            stack<int> s2;
            
            if (a == 0)
                return false;
            if (b == 0)
                return true;
            
            int tmp_a = a;
            int tmp_b = b;
            while (tmp_a) {
                s1.push(tmp_a % 10);
                tmp_a /= 10;
            }
            while (tmp_b) {
                s1.push(tmp_b % 10);
                tmp_b /= 10;
            }
            
            tmp_a = a;
            tmp_b = b;
            while (tmp_b) {
                s2.push(tmp_b % 10);
                tmp_b /= 10;
            }
            while (tmp_a) {
                s2.push(tmp_a % 10);
                tmp_a /= 10;
            }
            
            while (!s1.empty() && !s2.empty()) {
                if (s1.top() != s2.top()) {
                    return s1.top() < s2.top();
                } else {
                    s1.pop();
                    s2.pop();
                }
            }
            return true;
        });
        
        string s;
        
        while (nums.size() > 1 && nums[0] == 0 && nums[1] == 0)
            nums.erase(nums.begin());
        
        for (auto e : nums) {
            s += to_string(e);
        }
        return s;
    }
};
