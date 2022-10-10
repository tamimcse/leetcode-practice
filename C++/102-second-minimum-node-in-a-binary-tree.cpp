/*
https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/
*/
class Solution {

public:
    int findSecondMinimumValue(TreeNode* root) {
        int sec_min1, sec_min2;
        
        if (root->right == nullptr)
            return -1;
        if (root->left->val == root->right->val) {
            sec_min1 = findSecondMinimumValue (root->left);
            sec_min2 = findSecondMinimumValue (root->right);
            if (sec_min1 == -1)
                return sec_min2;
            if (sec_min2 == -1)
                return sec_min1;
            return min(sec_min1, sec_min2);
        } else {
            if (root->left->val < root->right->val) {
                sec_min1 = findSecondMinimumValue (root->left);
                if (root->right->val == 3)
                    cout << sec_min1;
                if (sec_min1 != -1)
                    return min (sec_min1, root->right->val);
                else
                    return root->right->val;
            } else {
                sec_min1 = findSecondMinimumValue (root->right);
                if (sec_min1 != -1)
                    return min (sec_min1, root->left->val);
                else
                    return root->left->val;
            }
        }
    }
};
