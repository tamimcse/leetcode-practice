/*
https://leetcode.com/problems/partition-labels/
*/
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int> startIdx(n);
        unordered_map<char, int> hash;
        vector<int> res;

        for (int i = 0; i < n; i++) {
            if (hash.find(s[i]) == hash.end()) {
                hash[s[i]] = i;
                startIdx[i] = i;
            } else {
                startIdx[i] = hash[s[i]];
            }
        }

        for (int i = 0; i < n; i++) {
            cout << startIdx[i] << " ";
        }
        cout << endl;

        for (int i = n - 1; i >= 0;) {
            int end = i, start = startIdx[i];
            while (i >= start) {
                start = min (start, startIdx[i]);
                i--;
            }
            res.push_back(end - i);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
