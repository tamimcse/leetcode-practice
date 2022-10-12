/*
https://leetcode.com/problems/valid-square/
*/
class Solution {
    int distance_square (vector<int>& p1, vector<int>& p2) {
        return pow (p1[0] - p2[0], 2) + pow (p1[1] - p2[1], 2);
    }

public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> points;
        points.push_back(p1);
        points.push_back(p2);
        points.push_back(p3);
        points.push_back(p4);
        
        sort (points.begin(), points.end(), [](vector<int>& p1, vector<int>& p2) {
            if (p1[0] == p2[0])
                return p1[1] <= p2[1]; 
            return p1[0] < p2[0];
        });
        
        return distance_square (points[0], points[1]) == distance_square (points[0], points[2]) &&
            distance_square (points[3], points[1]) == distance_square (points[3], points[2]) && 
            distance_square (points[0], points[1]) && distance_square (points[3], points[1]) && 
            distance_square (points[0], points[3]) == distance_square (points[1], points[2]);
    }
};
