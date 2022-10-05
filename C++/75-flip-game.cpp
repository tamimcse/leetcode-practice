/*
https://leetcode.com/problems/flip-game/
*/
class Solution {
public:
    vector<string> generatePossibleNextMoves(string currentState) {
        vector<string> res;
        
        for (int i = 1; i < currentState.length(); i++) {
            if (currentState[i] == '+' && currentState[i-1] == '+') {
                string s = currentState;
                s[i] = '-';
                s[i-1] = '-';
                res.push_back(s);
            }
        }
        return res;
    }
};
