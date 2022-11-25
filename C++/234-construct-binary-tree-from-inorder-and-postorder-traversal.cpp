/*
https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
*/
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int root_val = postorder.back();
        int n = inorder.size();
        TreeNode *left = NULL, *right = NULL;
        
        if (n == 1) {
            return new TreeNode(root_val);
        }
        
        int i = 0;
        for (; i < n; i++) {
            if (inorder[i] == root_val) {
                break;
            }
        }
        
        if (i > 0) {
            vector<int> inorder_new;
            vector<int> postorder_new;
            inorder_new.insert(inorder_new.end(), 
                               inorder.begin(), inorder.begin() + i);
            postorder_new.insert(postorder_new.end(),
                                postorder.begin(), postorder.begin() + i);
            left = buildTree (inorder_new, postorder_new);
        }
        
        if (i + 1 < n) {
            vector<int> inorder_new;
            vector<int> postorder_new;
            inorder_new.insert(inorder_new.end(), 
                               inorder.begin() + i + 1, inorder.end());
            postorder_new.insert(postorder_new.end(),
                                postorder.begin() + i, postorder.end()-1);
            right = buildTree (inorder_new, postorder_new);
        }
        
        return new TreeNode(root_val, left, right);
    }
};
