/*
https://leetcode.com/problems/design-add-and-search-words-data-structure/
*/
struct Node {
  unordered_map<char, Node *> child; 
  bool isLeaf;
  Node(char c) {
      isLeaf = false;
  }  
};

class WordDictionary {
    Node *root;
public:
    WordDictionary() {
        root = new Node('0');
    }
    
    void addWord(string word) {
        int n = word.length();
        Node *r = root;
        
        for (int i = 0; i < n; i++) {
            auto it = r->child.find(word[i]);
            if (it == r->child.end()) {
                r->child[word[i]] = new Node(word[i]);                
            }
            r = r->child[word[i]];
            if (i == n - 1)
                r->isLeaf = true;
        }
    }
    
    bool search(Node *r, string word) {
        int n = word.length();
        
        if (word == "")
            return r->isLeaf;
        
        int i;
        for (i = 0; i < n; i++) {
            if (word[i] == '.') {
                string substr = word.substr(i + 1);
                for (auto it = r->child.begin(); it != r->child.end(); it++) {
                    if(search(it->second, substr))
                        return true;
                }
                return false;
            }
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
    
    bool search(string word) {
        return search (root, word);
    }
};
