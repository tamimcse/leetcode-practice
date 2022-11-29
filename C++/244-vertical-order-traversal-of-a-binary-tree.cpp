/*
https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
*/
struct Elem {
  int x;
  int y;
  int val;
  Elem(int x_, int y_, int val_) {
      x = x_;
      y = y_;
      val = val_;
  }
};
struct Cmp {
  bool operator()(Elem &p1, Elem &p2) {
      if (p1.y != p2.y)
          return p1.y > p2.y;
      if (p1.x != p2.x) 
          return p1.x > p2.x;
      return p1.val > p2.val;
  }  
};
class Solution {
    void verticalTraversal(TreeNode* root,
                            priority_queue<Elem, vector<Elem>, Cmp> &pq,
                            int x, int y) {
        pq.push(Elem(x, y, root->val));
        if (root->left)
            verticalTraversal(root->left, pq, x + 1, y - 1);
        if (root->right)
            verticalTraversal(root->right, pq, x + 1, y + 1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        priority_queue<Elem, vector<Elem>, Cmp> pq;
        int last_col;
        int idx = 0; 
        
        verticalTraversal(root, pq, 0, 0);
        if (pq.empty())
            return res;
        res.push_back({pq.top().val});
        last_col = pq.top().y;
        pq.pop();
        
        while (!pq.empty()) {
            int num = pq.top().val;

            if (pq.top().y != last_col) {
                last_col = pq.top().y;
                res.push_back({});
                idx++;
            }
            pq.pop();
            res[idx].push_back(num);
        }
        return res;
    }
};
