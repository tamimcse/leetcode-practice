/*
https://leetcode.com/problems/logger-rate-limiter/

Here, Hash may contain many unnecessary entry. How to get rid of that?
*/
class Logger {
    unordered_map<string, int> hash;
public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        auto it = hash.find(message);
        if (it != hash.end()) {
            if (timestamp - it->second >= 10) {
                it->second = timestamp;
                return true;
            } else {
                return false;
            }
        }
        hash[message] = timestamp;
        return true;
    }
};
