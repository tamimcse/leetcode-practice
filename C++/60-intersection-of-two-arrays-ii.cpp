/*
https://leetcode.com/problems/intersection-of-two-arrays-ii/

Try this follow ups:

What if the given array is already sorted? How would you optimize your algorithm? (Reimplemet it by sorting the arrays)
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/
class Solution {
    #define LEN 1001
    
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        
        int count1[LEN] = {0};
        int count2[LEN] = {0};
        
        for (auto e : nums1) {
            count1[e]++;
        }
        
        for (auto e : nums2) {
            count2[e]++;
        }
        
        for (int i = 0; i < LEN; i++) {
            if (count1[i] && count2[i]) {
                for (int j = 0; j < min(count1[i], count2[i]); j++) {
                    res.push_back(i);    
                }
            }
        }
        
        return res;
    }
};

class Solution {
    #define LEN 1001
    
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int i = 0, j = 0;
        
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                res.push_back (nums1[i]);
                i++;
                j++;
            }
        }
        return res;
    }
};
