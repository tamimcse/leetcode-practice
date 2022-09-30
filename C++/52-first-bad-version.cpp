/*
https://leetcode.com/problems/first-bad-version/
*/
class Solution {
public:
    int firstBadVersion(int n) {
        long start = 1, end = n, mid;
        
        while (end >= start) {
            mid = ((long)start + end) >> 1;
            if (!isBadVersion(mid))
                start = mid + 1;
            else if (mid == 0 || !isBadVersion(mid - 1))
                return mid;
            else
                end = mid - 1;
        }
        return mid;
    }
};
