/*
https://leetcode.com/problems/unique-email-addresses/
*/
class Solution {
    string filter (string email) {
        bool first_part = true;
        bool found_plus = false;
        int idx = 0;
        
        for (int i = 0; i < email.length(); i++) {
            if (first_part && email[i] == '.')
                continue;
            if (first_part && email[i] == '+') {
                found_plus = true;
                continue;
            }
            if (first_part && found_plus && email[i] != '@')
                continue;
            if (email[i] == '@')
                first_part = false;
            email[idx++] = email[i];
        }
        
        return email.substr(0, idx);
    }
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string, bool> hash;
        
        for (auto e : emails) {
            string s = filter (e);
            hash[s] = true;
        }
        
        return hash.size();
    }
};
