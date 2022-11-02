/*
https://leetcode.com/problems/design-hashset/
*/
struct Node {
    int val;
    Node *next;
    Node(int v) {
        val = v;
        next = NULL;
    }
};


class MyHashSet {
    const static int size = 100;
    Node *arr[size] = {NULL};
public:
    MyHashSet() {
    }
    
    void add(int key) {
        if (contains(key))
            return;
        int idx = key % size;
        Node *n = new Node(key);
        n->next = arr[idx];
        arr[idx] = n;
    }
    
    void remove(int key) {
        int idx = key % size;
        Node *r = arr[idx];
        if (!r)
            return;
        if (r->val == key) {
            arr[idx] = arr[idx]->next;
            return;
        }
        while (r->next) {
            if (r->next->val == key) {
                r->next = r->next->next;
                return;
            }
            r = r->next;
        }      
    }
    
    bool contains(int key) {
        int idx = key % size;
        Node *r = arr[idx];
        while (r) {
            if (r->val == key)
                return true;
            r = r->next;
        }
        return false;
    }
};
