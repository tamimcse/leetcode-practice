/*
https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

Very very very very interesting problem!!

Implement both using hash and trie. When implementing hash based approch, I learned some cool thing, but eventuall decided not to use that approch. I only used trie based approach. 
*/
struct Node {
    bool isLeaf;
    Node *left, *right;
    Node() {
        isLeaf = false;
        left = NULL;
        right = NULL;
    }
};
class Trie {
    Node root;
    int bit_len;
public:
    Trie (int bit_len_) {
        bit_len = bit_len_;
    }
    void insert(int num) {
        int mask = 1 << (bit_len - 1);
        Node *r = &root;

        for (int i = bit_len; i >= 1; i--) {
            if (num & mask) {
                if (r->right == NULL)
                    r->right = new Node();
                r = r->right;
            } else {
                if (r->left == NULL)
                    r->left = new Node();
                r = r->left;
            }
            mask = mask >> 1;
        }
        r->isLeaf = true;
    }

    int find_max_or (int num) {
        int res = 0;
        Node *r = &root;
        int pat = 1 << (bit_len - 1);

        while (!r->isLeaf) {
            res = res << 1;
            if (pat & num) {
                if (r->left) {
                    res |= 1;
                    r = r->left;
                } else {
                    r = r->right;
                }
            } else {
                if (r->right) {
                    res |= 1;
                    r = r->right;
                } else {
                    r = r->left;
                }
            }
            pat = pat >> 1;
        }
        return res;        
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        int max_elem = *max_element (nums.begin(), nums.end());
        int num_bits = max_elem == 0 ? 1 : log10 (max_elem)/log10(2) + 1;

        Trie t (num_bits);
        for (auto e : nums) {
            t.insert(e);
        }

        int res = 0;
        for (auto e : nums) {
            res = max (res, t.find_max_or(e));
        }
        return res;
    }
};
