/*
https://leetcode.com/problems/design-hit-counter/

How can you make it scale such that it supports large number of hits per second? I know the way. Seem too trivial to implement. But, make sure you know it.
*/
class HitCounter {
    map<unsigned int, unsigned int> hitCountMap;
    int count = 0;
public:
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        if (hitCountMap.empty() || ((timestamp - hitCountMap.begin()->first) < 300)) {
            hitCountMap[timestamp]++;
            count++;
        } else {
            for (auto it = hitCountMap.begin(); it != hitCountMap.end();) {
                if ((timestamp - it->first) < 300)
                    break;
                count -= it->second;
                it = hitCountMap.erase(it);
            }
            hitCountMap[timestamp]++;
            count++;
        }
    }
    
    int getHits(int timestamp) {
        if (hitCountMap.empty() || ((timestamp - hitCountMap.begin()->first) < 300))
            return count;
        for (auto it = hitCountMap.begin(); it != hitCountMap.end();) {
            if ((timestamp - it->first) < 300)
                break;
            count -= it->second;
            it = hitCountMap.erase(it);
        }
        return count;
    }
};
