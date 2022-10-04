/*
https://leetcode.com/problems/logger-rate-limiter/

Here, Hash may contain many unnecessary entry. Reimplement it such that there is no unncessary entries in hash.
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

class Logger {
    unordered_map<string, int> hash;
    queue<pair<string, int>> queue;
public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        while (!queue.empty() &&  (timestamp - queue.front().second >= 10)) {
            hash.erase(queue.front().first);
            queue.pop();
        }
        
        auto it = hash.find(message);
        if (it != hash.end()) {
            return false;
        }
        hash[message] = timestamp;
        queue.push(make_pair(message, timestamp));
        return true;
    }
};
