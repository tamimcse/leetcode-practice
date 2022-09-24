/*
https://leetcode.com/problems/median-of-two-sorted-arrays/
*/
class Solution {
    const int magic_num = 1000001;
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        bool odd;
        int target, itr = 0;
        auto r1 = nums1.begin(), r2 = nums2.begin();
        int item1, item2;
        
        if ((n + m) & 1) {
            target = ((n + m) >> 1) + 1;
            odd = true;
        } else {
            target = (n + m) >> 1;
            odd = false; 
        }
        cout << target << endl;
        while (1) {
            item1 = r1 != nums1.end() ? *r1 : magic_num;
            item2 = r2 != nums2.end() ? *r2 : magic_num;
            if (itr == target - 1) {
                if (odd) {
                    return min (item1, item2);
                } else {
                    int a = min (item1, item2);
                    if (item1 < item2)
                        r1++;
                    else
                        r2++;
                    item1 = r1 != nums1.end() ? *r1 : magic_num;
                    item2 = r2 != nums2.end() ? *r2 : magic_num;
                    int b = min (item1, item2);
                    return (a + b)/2.0;
                }
            } else {
                if (item1 < item2)
                    r1++;
                else
                    r2++;
                itr++;
            }
        }
    }
};
