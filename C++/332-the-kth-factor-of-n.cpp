/*
https://leetcode.com/problems/the-kth-factor-of-n/
*/
class Solution {
public:
    int kthFactor(int n, int k) {
        int sq = sqrt (n);
        deque<int> dq;

        if (sq * sq == n) {
            dq.push_back(sq);
            sq--;
        }
            
        for (int i = sq; i >= 1; i--) {
            if (n % i == 0) {
                dq.push_front(i);
                dq.push_back(n/i);
            }
        }

        if (k > dq.size())
            return -1;
        return dq[k-1];
    }
};
