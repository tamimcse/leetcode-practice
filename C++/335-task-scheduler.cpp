/*
https://leetcode.com/problems/task-scheduler/

Very interesting problem!!
*/
struct Cmp {
  bool operator()(pair<char, int> &p1, pair<char, int> &p2) {
      return p1.second < p2.second;
  }  
};

class Solution {
    void insert(string &s, char c, int ) {
        
    }
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        pair<char, int> cur;
        unordered_map<char, int> hash;
        
        for (auto ch : tasks) {
            freq[ch - 'A']++;
        }
        
        priority_queue<pair<char, int>, vector<pair<char, int>>, Cmp> pq;
        
        for (int i = 0; i < 26; i++) {
            if (freq[i]) {
                pq.push(make_pair(i + 'A', freq[i]));
            }
        }
        
        string s;
        while (!pq.empty()) {
            cur = pq.top();
            pq.pop();
            //insert the character properly in the string
            auto it = hash.find (cur.first);
            if (it != hash.end()) {
                int j = hash[cur.first] + n + 1;
                bool inserted = false;
                while (j < s.length()) {
                    if (s[j] == '+') {
                        s[j] = cur.first;
                        hash[cur.first] = j;
                        inserted = true;
                        break;
                    }
                    j++;
                }
                if (!inserted) {
                    while (s.length() - 1 - hash[cur.first] < n) {
                        s += '+';
                    }
                    s += cur.first;
                    hash[cur.first] = s.length() - 1;
                }
            } else {
                bool inserted = false;
                for (int i = 0; i < s.length(); i++) {
                    if (s[i] == '+') {
                        s[i] = cur.first;
                        hash[cur.first] = i;
                        inserted = true;
                        break;
                    }
                }
                if (!inserted) {
                    s += cur.first;
                    hash[cur.first] = s.length() - 1;
                }
            }
            
            if (cur.second > 1) {
                cur.second--;
                pq.push(cur);
            }
        }

        return s.length();
    }
};
