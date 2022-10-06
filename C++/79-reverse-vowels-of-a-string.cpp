/*
https://leetcode.com/problems/reverse-vowels-of-a-string/
*/
class Solution {
    bool is_vowel (char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; 
    }
public:
    string reverseVowels(string s) {
        int start = 0, end = s.length() - 1;
        while (end > start) {
            while (start < s.length() && !is_vowel(s[start])) {
                start++;
            }
            while (end >= 0 && !is_vowel(s[end])) {
                end--;
            }
            if (end > start) {
                swap(s[start], s[end]);
                start++;
                end--;
            }
        }
        return s;
    }
};
