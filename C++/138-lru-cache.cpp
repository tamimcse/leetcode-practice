/*
https://leetcode.com/problems/lru-cache/
*/
class Node {
public:
    int key;
    int val;
    Node *next;
    Node *prev;
    Node(int k, int v) {
        key = k;
        val = v;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
    Node *head;
    Node *tail;
    unordered_map<int, struct Node *> hash;
    int max_size;
 
public:
    LRUCache(int capacity) {
        max_size = capacity;
        head = nullptr;
        tail = nullptr;
    }
    
    void move_to_front(Node *cur) {
        if (head == tail || head == cur) {
            return;
        }
        cur->prev->next = cur->next;
        if (cur->next)
            cur->next->prev = cur->prev;
        else
            tail = cur->prev;
        cur->next = head;
        head->prev = cur;
        head = cur;        
    }
    
    void remove_last () {
        Node *to_del = tail;
        if (tail->prev)
            tail->prev->next = nullptr;
        tail = tail->prev;
        if (!tail)
            head = nullptr;
        delete to_del;
    }
    
    void insert_front(int key, int val) {
        Node *n = new Node(key, val);
        if (!head) {
            head = n;
            tail = n;
            return;
        }
        n->next = head;
        head->prev = n;
        head = n;
    }
    
    int get(int key) {
        auto it = hash.find(key);
        if (it == hash.end())
            return -1;
        struct Node *cur = hash[key];
        move_to_front(cur);
        return head->val;
    }
    
    void put(int key, int value) {
        auto it = hash.find(key);
        if (it != hash.end()) {
            move_to_front(hash[key]);
            head->val = value;
            return;
        }
        if (hash.size() >= max_size) {
            int key_to_del = tail->key; 
            remove_last();
            hash.erase(key_to_del);
        }
        insert_front(key, value);
        hash[key] = head;
    }
};
