/*
https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
*/
class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26);
        vector<int> indices(26);
        int n = s.length();
        int res = 0;
        
        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
        }
        
        for (int i = 0; i < 26; i++) {
            indices[i] = i;
        }
        
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return freq[a] > freq[b];
        });
        
        int prev = freq[indices[0]];
        for (int i = 1; i < 26; i++) {
            if (freq[indices[i]] == 0)
                continue;
            if (freq[indices[i]] < prev) {
                prev = freq[indices[i]];
                continue;
            }
            res += freq[indices[i]] - prev + 1;
            freq[indices[i]] = prev - 1;
            if (prev > 1)
                prev--;        
        }
        
        return res;
    }
};
