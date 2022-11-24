/*
https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

Very interesting problem!
*/
struct Entry {
    int level;
    int x;
    int y;
    int val;
    Entry () {
        level = 0;
        x = 0;
        y = 0;
        val = 0;        
    }
    Entry (int l, int x_, int y_, int v) {
        level = l;
        x = x_;
        y = y_;
        val = v;
    }
};

struct Cmp {
    bool operator()(Entry &e1, Entry &e2) {
        return e1.val > e2.val;
    }  
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<Entry, vector<Entry>, Cmp> pq;
        vector<vector<int>> visit(n);
        Entry cur;
        int count = 0;
        
        for (auto &e : visit)
            e.resize(n);
        
        pq.push(Entry(0, 0, 0, matrix[0][0]));
        visit[0][0] = 1;
        while (!pq.empty()) {
            cur = pq.top();
            pq.pop();
            count++;
            if (count == k)
                return cur.val;
            if (cur.x + 1 < n && !visit[cur.x + 1][cur.y]) {
                pq.push(Entry(cur.level + 1, cur.x + 1, cur.y, matrix[cur.x + 1][cur.y]));
                visit[cur.x + 1][cur.y] = 1;
            }
            if (cur.y + 1 < n && !visit[cur.x][cur.y + 1]) {
                pq.push(Entry(cur.level + 1, cur.x, cur.y + 1, matrix[cur.x][cur.y + 1]));
                visit[cur.x][cur.y + 1] = 1;
            }
        }
        return -1;
    }
};
