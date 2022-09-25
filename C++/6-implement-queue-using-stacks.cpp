/*
https://leetcode.com/problems/implement-queue-using-stacks/
*/
class MyQueue {
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        while (s1.size() > 1) {
            s2.push(s1.top());
            s1.pop();
        }
        int res = s1.top();
        s1.pop();
        while (s2.size() > 0) {
            s1.push(s2.top());
            s2.pop();
        }
        return res;
    }
    
    int peek() {
        while (s1.size() > 1) {
            s2.push(s1.top());
            s1.pop();
        }
        int res = s1.top();
        while (s2.size() > 0) {
            s1.push(s2.top());
            s2.pop();
        }
        return res;
    }
    
    bool empty() {
        return s1.size() == 0;
    }
};

