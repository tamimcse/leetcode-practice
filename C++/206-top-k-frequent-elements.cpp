/*
https://leetcode.com/problems/top-k-frequent-elements/
*/
struct Cmp {
    bool operator()(pair<int, int> &p1, pair<int, int> &p2) {
        return p1.second > p2.second;
    }    
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq;
        vector<int> res(k);
        
        for (auto e : nums)
            hash[e]++;
        
        for (auto &e : hash) {
            pq.push(e);
            if (pq.size() > k)
                pq.pop();
        }
        
        for (int i = 0; i < k; i++) {
            res[i] = pq.top().first;
            pq.pop();
        }
        
        return res;
    }
};
