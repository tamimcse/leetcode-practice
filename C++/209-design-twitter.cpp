/*
https://leetcode.com/problems/design-twitter/
*/
struct Node {
    int time;
    int tweetID;
    Node *next;
    Node(int t, int tId) {
        time = t;
        tweetID = tId;
        next = NULL;
    }
};

struct Cmp {
    bool operator()(Node *&p1, Node *&p2) {
        return p1->time < p2->time;
    }    
};

class Twitter {
    unordered_map<int, vector<int>> followee;
    unordered_map<int, Node*> tweets;
    int time;
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        Node *n = new Node(time++, tweetId);
        n->next = tweets[userId];
        tweets[userId] = n;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<Node*, vector<Node*>, Cmp> pq;
        auto itr = tweets.find(userId);
        if (itr != tweets.end())
            pq.push(tweets[userId]);
        auto v = followee[userId];
        for (auto &e : v) {
            auto it = tweets.find(e);
            if (it != tweets.end())
                pq.push(tweets[e]);
        }
        
        vector<int> res;
        while (res.size() < 10 && !pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            if (cur->next)
                pq.push(cur->next);
            res.push_back(cur->tweetID);
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        for (auto it = followee[followerId].begin(); 
             it != followee[followerId].end(); it++) {
            if (*it == followeeId) {
                return;
            }
        }        
        followee[followerId].push_back(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        for (auto it = followee[followerId].begin(); 
             it != followee[followerId].end(); it++) {
            if (*it == followeeId) {
                followee[followerId].erase(it);
                return;
            }
        }
    }
};
