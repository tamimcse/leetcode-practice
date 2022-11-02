/*
https://leetcode.com/problems/design-hit-counter/

How can you make it scale such that it supports large number of hits per second? I know the way. Seem too trivial to implement. But, make sure you know it.
*/
class HitCounter {
    queue<int> q;
public:
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        q.push(timestamp);
    }
    
    int getHits(int timestamp) {
        while (!q.empty() && (timestamp - q.front() >= 300)) {
            q.pop();
        }
        return q.size();
    }
};
