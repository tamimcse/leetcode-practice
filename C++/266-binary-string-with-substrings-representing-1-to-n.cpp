/*
https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/

Actual problem was:

https://www.geeksforgeeks.org/interesting-method-generate-binary-numbers-1-n/

This is not an easy problem. Try to solved it in different ways.
*/


/*******This gets TLE******************************/

class Solution {
    vector<string> getBinStr(int n) {
        vector<string> res;
        string s = "1";

        res.push_back(s);
        for (int i = 1; i < n; i++) {
            if ((i & 1) == 0) {
                s[s.length() - 1] = '1';
            } else {
                int num = ((i ^ (i + 1)) >> 1) + 1;
                int count = log10(num) / log10(2);
                if (s.length() == count) {
                    s.insert(0, "1");
                }
                s[s.length() - count - 1] = '1';
                for (int k = s.length() - count; k < s.length(); k++) {
                    s[k] = '0';
                }
            }
            res.push_back(s);
        }
        return res;
    }
public:
    bool queryString(string s, int n) {
        int m = s.length();
        vector<string> pat = getBinStr(n);

        for (auto &e : pat) {
            if (s.find(e) == string::npos)
                return false;
        }
        return true;
    }
};


/**********This gets TLE ******************************************/

class Solution {
    vector<string> getBinStr(int n) {
        vector<string> res;
        queue<string> q;
        string cur;

        q.push("1");
        int i = 0;
        while (i < n) {
            cur = q.front();
            res.push_back(cur);
            i++;
            q.pop();
            q.push(cur + "0");
            q.push(cur + "1");
        }
        return res;
    }
public:
    bool queryString(string s, int n) {
        int m = s.length();
        vector<string> pat = getBinStr(n);

        for (auto &e : pat) {
            if (s.find(e) == string::npos)
                return false;
        }
        return true;
    }
};



/**********This gets TLE ******************************************/
class Solution {
    vector<string> getBinStr(int n) {
        vector<string> res;
        queue<string> q;
        string cur;

        q.push("1");
        int i = 0;
        while (i < n) {
            cur = q.front();
            res.push_back(cur);
            i++;
            q.pop();
            q.push(cur + "0");
            q.push(cur + "1");
        }

        int max_len = res.back().length();///Remove all the numbers whose length is smaller
        for (auto it = res.begin(); it != res.end();) {
            if (it->length() < max_len) {
                it = res.erase(it);
            } else {
                it++;
            }
        }
        return res;
    }
public:
    bool queryString(string s, int n) {
        int m = s.length();
        vector<string> pat = getBinStr(n);

        for (auto &e : pat) {
            cout << "e = " << e << endl;
            if (s.find(e) == string::npos)
                return false;
        }
        return true;
    }
};


/*******This solution also gets TLE******/
class Solution {
    void get_bitstr(int num_digits, string cur_str, vector<string> &res) {
       // cout << "cur_str = " << cur_str << endl;
        if (cur_str.length() == num_digits) {
            res.push_back(cur_str);
            return;
        }
        if (cur_str != "" && cur_str != "0")
            get_bitstr(num_digits, cur_str + "0", res);
        get_bitstr(num_digits, cur_str + "1", res);
    }

    string binary(int a) {
        string s;
        int res;

        while (a) {
            s += to_string(a % 2);
            a = a/2;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    vector<string> getBinStr(int n) {
        vector<string> res;
        int num_bit_digits = (log10(n) / log10(2)) + 1;

        if ((n & (n+1))) {
            while (((log10(n) / log10(2)) + 1) == num_bit_digits) {
                res.push_back(binary(n));
                n--;
            }
        }
        if (n == 0)
            return res;    
        num_bit_digits = (log10(n) / log10(2)) + 1;
        string cur_str;
        get_bitstr (num_bit_digits, cur_str, res);
        return res;
    }
public:
    bool queryString(string s, int n) {
        int m = s.length();
        vector<string> pat = getBinStr(n);

        for (auto &e : pat) {
           // cout << "e = " << e << endl;
            if (s.find(e) == string::npos)
                return false;
        }
        return true;
    }
};
