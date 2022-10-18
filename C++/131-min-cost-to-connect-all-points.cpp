/*
https://leetcode.com/problems/min-cost-to-connect-all-points/

Following solution is uses the same approach as the leetcode solution. But, it was getting TLE for a very large input (second last test case)
*/
class DisjointSet {
    vector<int> parent;
    //vector<int> rank;
public:    
    DisjointSet (int n) {
        parent = vector<int>(n);
        //rank = vector<int>(n);
        
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    
    int find (int n) {
        while (n != parent[n]) {
            n = parent[n];
        }
        return n;
    }
    
    bool merge (int a, int b) {
        int p1 = find (a);
        int p2 = find (b);
        
        if (p1 == p2)
            return false;
        parent[p1] = p2;
        /*
        if (rank[p1] == rank[p2]) {
            parent[p1] = p2;
            rank[p2]++;
        } else if (rank[p1] < rank[p2]) {
            parent[p1] = p2;
        } else {
            parent[p2] = p1;
        }*/
        return true;
    }
};



class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> edge_list;
        
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                vector<int> edge(3);
                edge[0] = i;
                edge[1] = j;
                edge[2] = abs (points[i][0] - points[j][0]) + 
                    abs (points[i][1] - points[j][1]);
                edge_list.push_back(edge);
            }
        }
        
        sort (edge_list.begin(), edge_list.end(), [](vector<int> &v1, vector<int> &v2) {
            return v1[2] <= v2[2];
        });
        
        DisjointSet ds(points.size());
        int cost = 0;
        int count = 0;
        for (auto &e : edge_list) {
            if (ds.merge(e[0], e[1])) {
                count++;
                cost += e[2]; 
                if (count == points.size() - 1)
                    return cost;
            }
        }
        return 0;
    }
};
