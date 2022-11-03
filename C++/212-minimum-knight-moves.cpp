/*
https://leetcode.com/problems/minimum-knight-moves/
*/
struct Node {
    int x;
    int y;
    int level;
    Node (int x_, int y_, int level_) {
        x = x_;
        y = y_;
        level = level_;
    }
};

struct HashFunc {
    int operator()(const pair<int, int> &p) const {
        return abs((p.first * p.second)) % 10000;
    }  
};
class Solution {
    int arr[8][2] = {{-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, 
                  {1, -2}, {2, -1}, {2, 1}, {1, 2}};
public:
    int minKnightMoves(int x, int y) {
        queue<Node> q1, q2;
        unordered_map<pair<int, int>, int, HashFunc> visit1, visit2;
        
        q1.push(Node(0, 0, 0));
        visit1[make_pair(0, 0)] = 0;
        q2.push(Node(x, y, 0));
        visit2[make_pair(x, y)] = 0;
        while (!q1.empty() && !q2.empty()) {
            Node n1 = q1.front();
            q1.pop();
            
            Node n2 = q2.front();
            q2.pop();

            auto it4 = visit2.find(make_pair(n1.x, n1.y));
            if (it4 != visit2.end())
                return n1.level + it4->second;
            
            auto it5 = visit1.find(make_pair(n2.x, n2.y));
            if (it5 != visit1.end())
                return n2.level + it5->second;
            
            for (int i = 0; i < 8; i++) {
                int to_add_x = n1.x + arr[i][0];
                int to_add_y = n1.y + arr[i][1];
                int to_add_level = n1.level + 1;
                auto itr = visit1.find(make_pair(to_add_x, to_add_y));
                if (itr == visit1.end()) {
                    q1.push(Node(to_add_x, to_add_y, to_add_level));
                    visit1[make_pair(to_add_x, to_add_y)] = to_add_level;
                }
            }            
            for (int i = 0; i < 8; i++) {
                int to_add_x = n2.x + arr[i][0];
                int to_add_y = n2.y + arr[i][1];
                int to_add_level = n2.level + 1;
                auto itr = visit2.find(make_pair(to_add_x, to_add_y));
                if (itr == visit2.end()) {
                    q2.push(Node(to_add_x, to_add_y, to_add_level));
                    visit2[make_pair(to_add_x, to_add_y)] = to_add_level;
                }
            }
        }
        return 0;
    }
};
