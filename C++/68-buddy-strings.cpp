/*
https://leetcode.com/problems/buddy-strings/
*/
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.length() == 0 || goal.length() == 0 ||
            s.length() != goal.length()) {
            return false;
        }
        
        int count[26] = {0};
        if (s == goal) {
            for (int i = 0; i < s.length(); i++) {
                count[s[i] - 'a']++;
                if (count[s[i] - 'a'] == 2)
                    return true;
            }
            return false;
        }
        
        int arr[2] = {-1, -1};
        
        int j = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != goal[i]) {
                if (j == 2)
                    return false;
                arr[j++] = i;
            }
        }
        if (j != 2)
            return false;
        
        return s[arr[0]] == goal[arr[1]] && s[arr[1]] == goal[arr[0]];
    }
};
