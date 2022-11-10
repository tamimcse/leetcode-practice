/*
https://leetcode.com/problems/word-break/
*/
class Node{
public:    
    unordered_map<char, Node*> child;
    bool is_leaf;
    Node() {
        is_leaf = false;
    }
};

class Trie {
    Node root;
public:    
    Trie() {    
    }
    
    void insert(string s) {
        int n = s.length();
        Node *r = &root;
        
        for (int i = 0; i < n; i++) {
            auto it = r->child.find(s[i]);
            if (it == r->child.end()) {
                r->child[s[i]] = new Node();
            }
            r = r->child[s[i]];
            if (i == n - 1) {
                r->is_leaf = true;
            }
        }
    }

    bool find(string s, Node *n, unordered_map<string, bool> &hash) {
        auto it = hash.find(s);
        if (it != hash.end())
            return hash[s];
        
        int len = s.length();
        Node *r = n;
        
        for (int i = 0; i < len; i++) {
            auto it = r->child.find(s[i]);
            if (it == r->child.end()) {
                hash[s] = false;
                return false;
            }
            r = r->child[s[i]];
            if (i == len - 1) {
                hash[s] = r->is_leaf;
                return r->is_leaf;
            }   
            if (r->is_leaf) {
                string substr = s.substr(i + 1);
                bool ret = find (substr, &root, hash);
                hash[substr] = ret;
                if (ret)
                    return ret;
                ret = find (substr, r, hash);
                if (ret)
                    return ret;
            }
        }
        hash[s] = false;
        return false;
    }
    
    bool find(string s) {
        unordered_map<string, bool> hash;
        int n = s.length();
        
        return find(s, &root, hash);
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie t;
        
        for (auto &e : wordDict) {
            t.insert(e);    
        }
        
        return t.find(s);
    }
};
