/*
https://leetcode.com/problems/delete-node-in-a-bst/

https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/

geeksforgeeks explanantion is better
*/
class Solution {
    TreeNode* deleteRoot(TreeNode* root) {
        if (root->left == NULL)
            return root->right;
        if (root->right == NULL)
            return root->left;
        
        TreeNode *new_root = root->left;
        TreeNode *to_insert = root->left->right;
        root->left->right = root->right;
        TreeNode *r = new_root;
        if (r->right)
            r = r->right;
        else {
            r->right = to_insert;
            return new_root;
        }
        while (r->left != NULL) {
            r = r->left;
        }
        r->left = to_insert;
        return new_root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return root;
        if (root->val == key) {
            return deleteRoot(root);
        }
        
        if (key <= root->val) {
            if (root->left && root->left->val == key) {
                root->left = deleteRoot(root->left);
                return root;
            } else {
                deleteNode (root->left, key);
            }
        } else {
            if (root->right && root->right->val == key) {
                root->right = deleteRoot(root->right);
                return root;
            } else {
                deleteNode (root->right, key);
            }
        }
        return root;
    }
};
