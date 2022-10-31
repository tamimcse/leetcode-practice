/*
https://leetcode.com/problems/reverse-words-in-a-string/
*/
class Solution {
    void reverseStr(string &s, int start, int end) {
        while (end > start) {
            swap(s[start++], s[end--]);
        }        
    }
public:
    string reverseWords(string s) {
        //Remove preceding spaces
        int num_spaces = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ')
                break;
            num_spaces++;
        }
        s.erase(0, num_spaces);

        //Remove internal spaces
        int idx = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == ' ' && s[i - 1] == ' ')
                continue;
            s[idx++] = s[i];
        }
        s.erase(idx);
        
        //Remove trailing spaces
        num_spaces = 0;
        for (int i = s.length() - 1; i > 0; i--) {
            if (s[i] != ' ') {
                if (num_spaces)
                    s.erase(i + 1);
                break;
            }
            num_spaces++;
        }
        
        reverseStr(s, 0, s.length() - 1);
        
        int start;
        for (int i = 0; i < s.length(); i++) {
            if ((i == 0 && isalnum(s[i])) || 
                (isalnum(s[i]) && s[i-1] == ' ')) {
                start = i;
            }
            if ((i > 0 && s[i] == ' ' && isalnum(s[i-1])) || 
                (isalnum(s[i]) && i == s.length() - 1))  {
                if (i < s.length() - 1)
                    reverseStr(s, start, i - 1);
                else
                    reverseStr(s, start, i);
            }
        }
        
        return s;
    }
};
