/*
https://leetcode.com/problems/reorganize-string/

https://www.geeksforgeeks.org/rearrange-characters-string-no-two-adjacent/

Both solution of geeksforgeeks are elegant.
*/
struct Cmp {
    bool operator()(pair<char, int> &p1, pair<char, int> &p2) {
        return p1.second < p2.second;
    }
};

class Solution {
public:
    string reorganizeString(string s) {
        int freq[26] = {0};

        for (auto c : s) {
            freq[c - 'a']++;
        }

        priority_queue<pair<char, int>, vector<pair<char, int>>, Cmp> pq;

        for (int i = 0; i < 26; i++) {
            if (freq[i])
                pq.push(make_pair(i+'a', freq[i]));
        }


        string res;
        char cur_ch = pq.top().first;
        int cur_freq = pq.top().second;
        res += cur_ch;
        char prev = cur_ch;
        pq.pop();
        if (cur_freq > 1)
            pq.push (make_pair(cur_ch, cur_freq - 1));
        while (!pq.empty()) {
            cur_ch = pq.top().first;
            cur_freq = pq.top().second;
            pq.pop();
            if (cur_ch != prev) {
                res += cur_ch;
                if (cur_freq > 1)
                    pq.push (make_pair(cur_ch, cur_freq - 1));
                prev = cur_ch;
            } else {
                if (pq.empty())
                    return "";
                char next_char = pq.top().first;
                char next_freq = pq.top().second;
                pq.pop();
                res += next_char;
                prev = next_char;
                if (next_freq > 1)
                    pq.push (make_pair(next_char, next_freq - 1));
                pq.push({cur_ch, cur_freq});
            }
        }
        return res;
    }
};
