/*
https://leetcode.com/problems/top-k-frequent-words/
*/
struct Cmp {
    bool operator() (pair<string, int> &p1, pair<string, int> &p2) {
        if (p1.second != p2.second)
            return p1.second < p2.second;
        return p1.first > p2.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> hash;
        priority_queue<pair<string, int>, vector<pair<string, int>>, Cmp> pq;
        
        for (auto &e : words) {
            hash[e]++;
        }
        
        for (auto &e : hash) {
            pq.push(e);
        }
        
        vector<string> res;
        for (int i = 0; i < k; i++) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};
