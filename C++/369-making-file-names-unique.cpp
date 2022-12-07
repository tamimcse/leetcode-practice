/*
https://leetcode.com/problems/making-file-names-unique/

It was getting TLE, but passed 31/33 test cases
*/

class Solution {
    void get_original(string s, string &orig, int &num) {
        int n = s.length();

        if (s[n-1] != ')') {
            orig = s;
            num = -1;
            return;
        }

        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == '(') {
                orig = s.substr(0, i);
                num = atoi(s.substr(i + 1, n - 1 - i).c_str());
                return;                
            }
        } 
        orig = s;
        num = -1;
        return;
    }
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, vector<int>> hash;
        vector<string> res;
        string key;

        for (auto s : names) {
            string orig;
            int num = -1;
            get_original(s, orig, num);
            if (num != -1 && num != 0) {
                auto itr = hash.find(orig);
                if (itr != hash.end()) {
                    sort (hash[orig].begin(), hash[orig].end());
                    int min_missing = 0;
                    for (int i = 0; i < hash[orig].size(); i++, min_missing++) {
                        if (hash[orig][i] != min_missing)
                            break;
                    }
                    
                    if (min_missing == num) {
                        hash[orig].push_back(num);
                        res.push_back(s);
                        hash[s].push_back(0);
                        continue;
                    } else {
                        bool found = false;
                        for (int i = 0; i < hash[orig].size(); i++) {
                            if (num == hash[orig][i]) {
                                found = true;
                                break;
                            }
                        }
                        if (!found)
                            hash[orig].push_back(num);
                    }
                } else {
                    hash[orig].push_back(num);
                }
            }

            auto it = hash.find(s);
            if (it != hash.end()) {
                //find smallest number;
                sort (hash[s].begin(), hash[s].end());
                int min_missing = 0;
                for (int i = 0; i < hash[s].size(); i++, min_missing++) {
                    if (hash[s][i] != min_missing)
                        break;
                }
                hash[s].push_back(min_missing);
                if (min_missing == 0) {
                    res.push_back(s);
                } else {
                    string tmp = s + "(" + to_string(min_missing) + ")";
                    res.push_back(tmp);
                    hash[tmp].push_back(0);
                }
            } else {
                hash[s].push_back(0);
                res.push_back(s);
            }
        }
        
        return res;
    }
};
