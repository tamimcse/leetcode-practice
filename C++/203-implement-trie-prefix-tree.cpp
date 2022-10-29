/*
https://leetcode.com/problems/implement-trie-prefix-tree/
*/
struct Node {
  unordered_map<char, Node *> child; 
  bool isLeaf;
  Node() {
      isLeaf = false;
  }  
};

class Trie {
    Node *root;
public:
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
            if (i == n - 1)
                r->isLeaf = true;
        }        
    }
    
    bool search(string word) {
        int n = word.length();
        
        Node *r = root;
        int i;
        for (i = 0; i < n; i++) {
            auto it = r->child.find(word[i]);
            if (it != r->child.end()) {
                if (i == n - 1)
                    return it->second->isLeaf;
                r = it->second;
            } else {
                return false;
            }
        }
        
        return false;
    }
    
    bool startsWith(string prefix) {
        if (prefix == "")
            return true;
        int n = prefix.length();
        
        Node *r = root;
        int i;
        for (i = 0; i < n; i++) {
            auto it = r->child.find(prefix[i]);
            if (it != r->child.end()) {
                r = it->second;
            } else {
                return false;
            }
        }
        return true;
    }
};
