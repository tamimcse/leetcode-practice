/*
https://leetcode.com/problems/rearrange-spaces-between-words/
*/
class Solution {
public:
    string reorderSpaces(string text) {
        int num_words = 0;
        int num_spaces = 0;
        
        for (int i = 0; i < text.length(); i++) {
            if (text[i] == ' ')
                num_spaces++;
            if ((i == 0 && text[i] != ' ') || (i > 0 && text[i] != ' ' && text[i-1] == ' '))
                num_words++;
        }
        
        int space_len = (num_words == 1) ? 0 : num_spaces / (num_words - 1);
        int end_space_len = (num_words == 1) ? num_spaces : num_spaces % (num_words - 1);

        string res;
        res.resize(text.length());
       
        int spaces_put = 0;
        int idx = 0;
        for (int i = 0; i < text.length(); i++) {
            if (text[i] != ' ')
                res[idx++] = text[i];
            else if (i > 0 && text[i] == ' ' && text[i-1] != ' ' && spaces_put < num_words - 1) {
                int count = space_len;
                while (count > 0) {
                    res[idx++] = ' ';
                    count--;
                }
                spaces_put++;
            }
        }
        
        while (end_space_len > 0) {
            res[idx++] = ' ';
            end_space_len--;
        }
        
        return res;
    }
};
