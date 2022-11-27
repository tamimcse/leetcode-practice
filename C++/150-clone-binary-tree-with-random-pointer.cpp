/*
https://leetcode.com/problems/clone-binary-tree-with-random-pointer/
*/
class Solution {
    NodeCopy* copyTree(Node* root, unordered_map<Node*, NodeCopy*> &hash) {
        NodeCopy *n = new NodeCopy(root->val);
        hash[root] = n;
        
        if (root->left)
            n->left = copyTree(root->left, hash);
        
        if (root->right)
            n->right = copyTree(root->right, hash);
        
        return n;
    }
    
    void copyRandPtr(Node* root, unordered_map<Node*, NodeCopy*> &hash) {
        if (root->random)
            hash[root]->random = hash[root->random];
        
        if (root->left)
            copyRandPtr(root->left, hash);
        
        if (root->right)
            copyRandPtr(root->right, hash);
    }
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
        unordered_map<Node*, NodeCopy*> hash;
        
        if (!root)
            return nullptr;
        
        NodeCopy *new_root = copyTree (root, hash);
        copyRandPtr(root, hash);
        return new_root;
    }
};
