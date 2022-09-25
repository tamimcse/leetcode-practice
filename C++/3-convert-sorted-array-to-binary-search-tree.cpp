/*
https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
*/
class Solution {
    TreeNode* sortedArrayToBST_inner(vector<int>& nums, int start, int end) {
        if(start > end)
            return nullptr;
        int mid = (start + end) >> 1;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST_inner (nums, start, mid - 1);
        root->right = sortedArrayToBST_inner (nums, mid + 1, end);
        return root;
    }    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST_inner(nums, 0, nums.size() - 1);
    }
};
