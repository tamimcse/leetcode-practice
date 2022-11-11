/*
https://leetcode.com/problems/max-stack/
*/
class MaxStack {
    map<int, int> ordered_elemets;
    multimap<int, int> max_elements;
    int idx;
public:
    MaxStack() {
        idx = 0;
    }
    
    void push(int x) {
        ordered_elemets[idx] = x;
        max_elements.insert(make_pair(x, idx));
        idx++;
    }
    
    int pop() {
        auto it = ordered_elemets.rbegin();
        int idx = it->first;
        int val = it->second;
        auto itr = max_elements.upper_bound(val);
        --itr;
        max_elements.erase(itr);
        ordered_elemets.erase(idx);
        return val;
    }
    
    int top() {
        return ordered_elemets.rbegin()->second;
    }
    
    int peekMax() {
        return max_elements.rbegin()->first;
    }
    
    int popMax() {
        auto it = max_elements.rbegin();
        int val = it->first;
        int idx = it->second;
        auto itr = max_elements.upper_bound(val);
        --itr;
        max_elements.erase(itr);
        ordered_elemets.erase(idx);
        return val;
    }
};

