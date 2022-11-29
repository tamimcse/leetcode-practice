/*
https://leetcode.com/problems/insert-delete-getrandom-o1/
*/
class RandomizedSet {
    unordered_set<int> us;
public:
    RandomizedSet() {
        srand(time(nullptr));
    }
    
    bool insert(int val) {
        if (us.count(val) == 0) {
            us.insert(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if (us.count(val)) {
            us.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int size = us.size();
        int idx = rand() % size;
        auto it = us.begin();
        advance(it, idx);
        return *it;
    }
};

