/*
https://leetcode.com/problems/find-median-from-data-stream/
*/
struct CmpMin {
    bool operator()(int a, int b) {
        return a > b;
    }    
};

struct CmpMax {
    bool operator()(int a, int b) {
        return a < b;
    }    
};

class MedianFinder {
    priority_queue<int, vector<int>, CmpMin> pqmin;
    priority_queue<int, vector<int>, CmpMax> pqmax;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(pqmax.empty()) {
            pqmax.push(num);
        } else if (pqmin.empty()) {
            if (num > pqmax.top()) {
                pqmin.push(num);
            } else {
                pqmax.push(num);
                pqmin.push(pqmax.top());
                pqmax.pop();
            }
        } else {
            if (num < pqmax.top()) {
                pqmax.push(num);
            } else {
                pqmin.push(num);
            }
            
            if (pqmax.size() == pqmin.size() + 2) {
                pqmin.push(pqmax.top());
                pqmax.pop();
            } else if (pqmin.size() == pqmax.size() + 1) {
                pqmax.push(pqmin.top());
                pqmin.pop();
            }
        }
    }
    
    double findMedian() {
        if (pqmin.size() != pqmax.size())
            return pqmax.top();
        else 
            return (pqmax.top() + pqmin.top())/2.0;
    }
};

