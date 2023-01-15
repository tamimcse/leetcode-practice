/*
https://leetcode.com/problems/longest-consecutive-sequence/

Very very intersing problem!!!

Problem isn't very clear. What does it mean by sequnce? Here, they mean longest range where each element of the range is a member of the array.

Sometimes, you may come across a problem where you need to check if you came through this path. This problem particularly arise in sequence building. In that, check if you can solve this using DFS/BFS. Usually you can. An example of such problem is longest-consecutive-sequence.

But, note that, here node node will have just one successor. Do you really need traditional recursive or stack based DFS here? No, you can implemement the DFS by a simple loop!!!!!!
Implementing stack based DFS results in TLE 

https://leetcode.com/problems/longest-consecutive-sequence/solution/
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> hash;
        unordered_set<int> not_start_nodes;

        for (auto e : nums) {
            if (hash.find(e + 1) != hash.end()) {
                hash[e] = true;
                not_start_nodes.insert(e + 1);
            }
            if (hash.find(e - 1) != hash.end()) {
                hash[e-1] = true;
                not_start_nodes.insert(e);
            }
            if (hash.find(e) == hash.end()) {
                hash[e] = false;
            }
        }

        int res = 0;
        for (auto e : nums) {
            if (not_start_nodes.count(e) == 0) {
                int num = e;
                int count = 1;
                while (hash[num] == true) {
                    num++;
                    count++;
                }
                res = max (res, count);
            }
        }

        return res;

    }
};
