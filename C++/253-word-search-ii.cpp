/*
https://leetcode.com/problems/word-search-ii/
*/
struct Node {
  unordered_map<char, Node *> child; 
  bool isLeaf;
  string val;  
  Node() {
      isLeaf = false;
  }  
};

class Trie {
    
public:
    Node *root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        int n = word.length();
        Node *r = root;
        
        for (int i = 0; i < n; i++) {
            auto it = r->child.find(word[i]);
            if (it == r->child.end()) {
                r->child[word[i]] = new Node();                
            }
            r = r->child[word[i]];
            if (i == n - 1) {
                r->isLeaf = true;
                r->val = word;
            }
        }        
    }
    
    bool startsWith(char ch) {
        auto it = root->child.find(ch);
        return it != root->child.end();
    }
};

class Solution {
    int arr[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    void dfs(vector<vector<char>>& board, int x, int y, Node *r,
             vector<vector<bool>> &visit, 
             unordered_set<Node*> &os, vector<string> &res) {
        int m = board.size(), n = board[0].size(), p, q;

        if (r->child[board[x][y]]->isLeaf) {
            if(!os.count(r->child[board[x][y]])) {
                os.insert(r->child[board[x][y]]);
                res.push_back(r->child[board[x][y]]->val);   
            }     
        }
        
        r = r->child[board[x][y]];
        visit[x][y] = true;
        
        for (int i = 0; i < 4; i++) {
            p = x + arr[i][0];
            q = y + arr[i][1];
            if (p >= 0 && p < m && q >= 0 && q < n && !visit[p][q]) {
                auto it = r->child.find(board[p][q]);
                if (it != r->child.end())
                    dfs(board, p, q, r, visit, os, res);
            }
        }
        visit[x][y] = false;
    }
public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        vector<string> res;
        Trie t;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visit(m);
        unordered_set<Node*> os;

        for (int i = 0; i < m; i++)
            visit[i].resize(n);
        
        for (auto &e : words)
            t.insert(e);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (t.startsWith(board[i][j])) {
                    dfs(board, i, j, t.root, visit, os, res);
                }
            }
        }
        
        return res;
    }
};
