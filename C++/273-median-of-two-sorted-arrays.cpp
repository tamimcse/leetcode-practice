/*
https://leetcode.com/problems/median-of-two-sorted-arrays/
*/
struct CmpMax {
    bool operator()(int a, int b) {
        return a < b;
    }    
};
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<int, vector<int>, CmpMax> pq;
        int m = nums1.size(), n = nums2.size();
        
        int mid = ((m + n) >> 1) + 1, i = 0, j = 0;

        while (mid) {
            if (i < m && j < n) {
                if (nums1[i] <= nums2[j]) {
                    pq.push(nums1[i++]);
                } else {
                    pq.push(nums2[j++]);
                }
            } else if (i < m) {
                pq.push(nums1[i++]);
            } else {
                pq.push(nums2[j++]);
            }
            mid--;
        }
        
        if ((m + n) & 1 == 1) {
            return pq.top();
        } else {
            int a = pq.top();
            pq.pop();
            return  (a + pq.top())/2.0;
        }
    }
};
