/*
https://leetcode.com/problems/lfu-cache/
*/
struct Node {
    int key;
    int val;
    int freq;
    Node *next;
    Node *prev;
    Node(int k, int v, int f) {
        key = k;
        val = v;
        freq = f;
        next = NULL;
        prev = NULL;
    }
};

class LFUCache {
    unordered_map<int, Node *> hash;
    map<int, pair<Node*, Node*>> freq_list;
    int size;
    
    void insert_last(Node* &head, Node* &tail, Node *to_insert) {
        if (!head) {
            head = to_insert;
            tail = to_insert;
        } else {
            tail->next = to_insert;
            to_insert->prev = tail;
            tail = tail->next;
        } 
    }
    
    void delete_cur(Node* &head, Node* &tail, Node *to_del) {
        if (head == to_del) {
            head = head->next;
            if (head)
                head->prev = NULL;
            else
                tail = NULL;
        } else if (tail == to_del) {
            tail->prev->next = NULL;
            tail = tail->prev;
        } else {
            if (to_del->next) {
                to_del->next->prev = to_del->prev;   
            }
            to_del->prev->next = to_del->next;
        }
        to_del->next = NULL;
        to_del->prev = NULL;
    }
    
    void print_freq() {
        cout << "printing freq list:\n";
        for (auto it = freq_list.begin(); it != freq_list.end(); it++) {
            Node *r = it->second.first;
            while (r) {
                cout << "key = " << r->key << " value = " << r->val << " freq = " << r->freq << endl;
                r = r->next;
            }
        }
    }
    void delete_frm_freq (int key) {
        delete_cur(freq_list[hash[key]->freq].first, freq_list[hash[key]->freq].second, hash[key]);
        if (freq_list[hash[key]->freq].first == NULL) {
            freq_list.erase(hash[key]->freq);         
        }
        hash.erase(key);
    }
    
    void move_upper (int key) {
        delete_cur(freq_list[hash[key]->freq].first, freq_list[hash[key]->freq].second, hash[key]);
        if (freq_list[hash[key]->freq].first == NULL) {
            freq_list.erase(hash[key]->freq);   
        }
        hash[key]->freq++;
        insert_last(freq_list[hash[key]->freq].first, freq_list[hash[key]->freq].second, hash[key]);        
    }
public:
    LFUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if (size == 0)
            return -1;
        auto it = hash.find(key);
        if (it == hash.end())
            return -1;
        move_upper(key);
        return hash[key]->val;
    }
    
    void put(int key, int value) {
        if (size == 0)
            return;
        auto it = hash.find(key);
        if (it != hash.end()) {
            move_upper(key);
            hash[key]->val = value;
        } else {
            if (hash.size() == size) {
                int key_to_del = freq_list.begin()->second.first->key;
                delete_frm_freq(key_to_del);
            }
            Node *n = new Node(key, value, 1);
            insert_last(freq_list[1].first, freq_list[1].second, n);
            hash[key] = n;
        }
    }
};
