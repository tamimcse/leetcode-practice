/*
https://leetcode.com/problems/kth-largest-element-in-a-stream/
*/
class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int th;
public:
    KthLargest(int k, vector<int>& nums) {
        for (auto e : nums) {
            pq.push(e);
        }

        th = k;
        
        int num_delete = nums.size() - k;
        for (int i = 0; i < num_delete; i++) {
            if (!pq.empty())
                pq.pop();
        }
    }
    
    int add(int val) {
        if (pq.size() < th) {
            pq.push(val);
        } else if (val > pq.top()) {
            pq.pop();
            pq.push(val);   
        }
        return pq.top();
    }
};
