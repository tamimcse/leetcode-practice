/*
https://leetcode.com/problems/encode-and-decode-strings/

Implement both approach:

1. Using delemeter 
2. Generic approach where it works for any possible characters
*/
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = strs[0];


        for (int i = 1; i < strs.size(); i++) {
            res += 257;
            res += strs[i];
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int start = 0;
        int end;

        do {
            end = s.find(257, start);
            if (end == string::npos)
                res.push_back(s.substr(start));
            else
                res.push_back(s.substr(start, end - start));
            start = end + 1;    
        } while (end != string::npos);
        return res;
    }
};


class Codec {
    string encode_len(string s) {
        string res = to_string(s.length());

        while (res.length() < 3) {
            res = "0" + res;
        }
        return res;
    }

public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;
        
        for (int i = 0; i < strs.size(); i++) {
            res += encode_len(strs[i]);
            res += strs[i];
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int start = 0;
        int end;
        int len;

        while (start < s.length()) {
            len = atoi(s.substr(start, 3).c_str());
            start += 3;
            res.push_back(s.substr(start, len));
            start += len;
        }
        return res;
    }
};
