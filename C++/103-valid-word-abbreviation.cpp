/*
https://leetcode.com/problems/valid-word-abbreviation/
*/
class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;
        while (i < word.length() && j < abbr.length()) {
            if (isdigit(abbr[j]) && abbr[j] != '0') {
                int k = j;
                while (k < abbr.length() && isdigit(abbr[k])) {
                    k++;
                }
                int skip = stoi(abbr.substr(j, k -j));
                if (i + skip - 1 >= word.length())
                    return false;
                i += skip;
                j = k;
            } else if (word[i] != abbr[j]) {
                return false;
            } else {
                i++;
                j++;
            }
        }
        return i == word.length() && j == abbr.length();       
    }
};
