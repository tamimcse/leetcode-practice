/*
https://leetcode.com/problems/clone-graph/
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return node;
        
        Node *new_head = new Node(node->val);
        queue<Node*> q1, q2;
        unordered_map<Node*, bool> visit;
        unordered_map<Node*, Node*> hash;
        Node *cur1, *cur2, *new_node;
        
        hash[node] = new_head;
        q1.push(node);
        q2.push(new_head);
        while (!q1.empty()) {
            cur1 = q1.front();
            cur2 = q2.front();
            q1.pop();
            q2.pop();
            
            if (visit.find(cur1) != visit.end())
                continue;
            visit[cur1] = true;
            for (auto &e : cur1->neighbors) {
                if (visit.find(e) != visit.end()) {
                    cur2->neighbors.push_back(hash[e]);
                    continue;
                }
                if(hash.find(e) != hash.end())
                    new_node = hash[e];
                else
                    new_node = new Node(e->val);
                cur2->neighbors.push_back(new_node);
                q1.push(e);
                q2.push(new_node);
                hash[e] = new_node;
            }
        }
        
        return new_head;
    }
};
