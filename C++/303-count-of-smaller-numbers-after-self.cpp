/*
https://leetcode.com/problems/count-of-smaller-numbers-after-self/
*/
class Solution {
    void countSmaller(vector<int>& nums, vector<int>& indices,
                      int start, int end, vector<int> &res) {
        int to_insert;                  
        int mid = (start + end) >> 1;

        if (start == end)
            return;

        countSmaller (nums, indices, start, mid, res);
        countSmaller (nums, indices, mid + 1, end, res);

        vector<int> tmp(end - start + 1);

        int num_moves = 0;
        for (int i = 0, j = start, k = mid + 1; i < end - start + 1; i++) {
            if (j <= mid && k <= end) {
                if (nums[indices[j]] <= nums[indices[k]]) {
                    res[indices[j]] += num_moves;
                    tmp[i] = indices[j++]; 
                } else {
                    num_moves++;
                    tmp[i] = indices[k++];
                }
            } else if (j <= mid) {
                res[indices[j]] += num_moves;
                tmp[i] = indices[j++];
            } else {
                tmp[i] = indices[k++];
            }
        }
        move(tmp.begin(), tmp.end(), indices.begin() + start);
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();

        vector<int> res(n);
        vector<int> indices(n);

        for (int i = 0; i < n; i++)
            indices[i] = i;

        countSmaller(nums, indices, 0, n - 1, res);

        return res;
    }
};
