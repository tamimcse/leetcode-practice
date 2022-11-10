/*
https://leetcode.com/problems/word-break-ii/
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
    void insert(string s) {
        int n = s.length();
        Node *r = &root;
        
        for (int i = 0; i < n; i++) {
            auto it = r->child.find(s[i]);
            if (it == r->child.end())
                r->child[s[i]] = new Node();
            r = r->child[s[i]];
            if (i == n - 1)
                r->is_leaf = true;
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        Node *r = &root;
        vector<string> res;
        
        for (int i = 0; i < n; i++) {
            auto it = r->child.find(s[i]);
            if (it == r->child.end()) {
                return res;
            }
            r = r->child[s[i]];
            if (i == n - 1 && !(r->is_leaf))
                return res;
            if (r->is_leaf) {
                if (i == n - 1) {
                    res.push_back(s);
                    return res;
                }
                string substr = s.substr(i + 1);
                vector<string> ret = wordBreak (substr, wordDict);
                string first_part = s.substr(0, i + 1);
                for (auto &e : ret) {
                    res.push_back(first_part + " " + e);
                }
            }
        }
        return res;
    }
};


class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie t;
        
        for (auto &e : wordDict) {
            t.insert(e);    
        }
        
        return t.wordBreak (s, wordDict);
    }
};
