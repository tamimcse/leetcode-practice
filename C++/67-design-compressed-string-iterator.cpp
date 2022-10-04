/*
https://leetcode.com/problems/design-compressed-string-iterator/
*/
class StringIterator {
    vector<pair<char, int>> vec;
    int idx;
public:
    StringIterator(string compressedString) {
        int i = 0, j;
        char ch;
        int count;
        while (i < compressedString.length()) {
            ch = compressedString[i];
            j = i + 1;
            while (j < compressedString.length() && isdigit(compressedString[j])) {
                j++;
            }
            string str = compressedString.substr(i + 1, j - 1);
            count = atoi(str.c_str());
            vec.push_back (make_pair(ch, count));
            i = j;       
        }
        idx = 0;
    }
    
    char next() {
        if (idx >= vec.size())
            return ' ';
        char ret = vec[idx].first;
        vec[idx].second--;
        if (!vec[idx].second)
            idx++;
        return ret;
    }
    
    bool hasNext() {
        return idx < vec.size();
    }
};
