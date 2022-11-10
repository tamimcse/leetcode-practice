/*
https://leetcode.com/problems/min-stack/
*/
class MinStack {
    stack<int> s1;
    stack<int> s2;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (s1.empty()) {
            s1.push(val);
            s2.push(val);
        } else {
            if (val <= s2.top()) {
                s2.push(val);
            }
            s1.push(val);
        }
    }
    
    void pop() {
        if (s1.top() == s2.top())
            s2.pop();
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};
