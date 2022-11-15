/*
https://leetcode.com/problems/group-anagrams/
*/
struct HashFunc {
    int operator()(const vector<int> &v) const {
        int sum = 0;
        
        for (auto e : v) {
            sum += e;
        }
        return sum;
    }    
};

class Solution {
    vector<int> calc_key(string s) {
        vector<int> freq(26);
        
        for (int i = 0; i < s.length(); i++) {
            freq[s[i]-'a']++;
        }
        return freq;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<vector<int>, vector<string>, HashFunc> hash;
        
        for (auto &e : strs) {
            vector<int> key = calc_key (e);
            hash[key].push_back(e);
        }
        
        for (auto it = hash.begin(); it != hash.end(); it++) {
            res.push_back(it->second);
        }
        return res;
    }
};
