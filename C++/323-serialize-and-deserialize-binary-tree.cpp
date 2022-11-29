/*
https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
*/
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        queue<TreeNode*> q;
        TreeNode *cur;
        
        q.push(root);
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            if (res != "")
                res += ",";
            if (cur)
                res += to_string(cur->val);
            else
                res += "NULL";
            if (cur) {
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int start = 0;
        int n = data.length();
        string s;
        TreeNode *root = NULL;
        queue<TreeNode*> q;
        TreeNode *cur, *parent;
        bool left = true;
        
        for (int i = 0; i < n; i++) {
            if (data[i] == ',' || i == n - 1) {
                if (data[i] == ',')
                    s = data.substr(start, i - start);
                else
                    s = data.substr(start);
                if (s != "NULL") {
                    if (!root) {
                        root = new TreeNode(atoi(s.c_str()));
                        q.push(root);
                    } else {
                        if (left) {
                            parent = q.front();
                            q.pop();
                            cur = new TreeNode(atoi(s.c_str()));
                            q.push(cur);
                            parent->left = cur;
                            left = false;
                        } else {
                            cur = new TreeNode(atoi(s.c_str()));
                            q.push(cur);
                            parent->right = cur;
                            left = true;
                        }
                    }
                } else {
                    if (left) {
                        parent = q.front();
                        q.pop();
                        left = false;
                    } else {
                        left = true;
                    }
                }
                start = i + 1;
            }
        }
        return root;
    }
};
