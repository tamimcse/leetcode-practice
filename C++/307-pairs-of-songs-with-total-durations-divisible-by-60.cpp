/*
https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

Quite intersting problem, even though look simple
*/
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        long count = 0, n = time.size();
        vector<int> freq(60);

        for (int i = 0; i < n; i++) {
            freq[time[i] % 60]++;
        }

        if (freq[0] > 1)
            count += (((long)freq[0] - 1) * freq[0]) >> 1; 
        if (freq[30] > 1)
            count += (((long)freq[30] - 1) * freq[30]) >> 1;
        for (int i = 1; i < 30; i++) {
            count += ((long)freq[i] * freq[60-i]);
        }    
        return count;
    }
};
