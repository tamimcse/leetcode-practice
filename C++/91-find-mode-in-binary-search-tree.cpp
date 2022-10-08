/*
https://leetcode.com/problems/find-mode-in-binary-search-tree/

Implement it not using Hash.
*/
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<pair<int, int>> res;
        vector<int> act_res;
        int last = 0, last_count = 0;
        stack<TreeNode*> s;
        TreeNode *cur;
        
        if (!root)
            return act_res;
        
        TreeNode *r = root;
        while (r) {
            s.push(r);
            r = r->left;
        }
        while (!s.empty()) {
            cur = s.top();
            s.pop();
            
            //visit
            if (cur->val != last) {
                if (last_count > 0 && (res.size() == 0 || last_count >= res.back().second))
                    res.push_back(make_pair(last, last_count));
                last = cur->val;
                last_count = 1;
            } else {
                last_count++;
            }
            r = cur->right;
            while (r) {
                s.push(r);
                r = r->left;
            }
        }
 
        if(last_count > 0 && (res.size() == 0 || last_count >= res.back().second))
            res.push_back(make_pair(last, last_count));
        
        int max = res[0].second;
        for (int i = 1; i < res.size(); i++) {
            if (res[i].second > max)
                max = res[i].second;
        }
        
        for (int i = 0; i < res.size(); i++) {
            
            if (res[i].second == max)
                act_res.push_back(res[i].first);
        }
        return act_res;
    }
};
