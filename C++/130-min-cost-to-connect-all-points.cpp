/*
https://leetcode.com/problems/min-cost-to-connect-all-points/

Following solution is uses the same approach as the leetcode solution.
*/
class Compare
{
public:
    bool operator() (pair<long long, int> &p1, pair<long long, int> &p2)
    {
        return p1.first > p2.first;
    }
};

class Solution {
    long long distance (vector<int> &p1, vector<int> &p2) {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int numPoints = points.size();
        set<int> set;
        int sum = 0;
        int currentNode = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, Compare> pq;

        set.insert(0);
        while (set.size() < numPoints) {
            for (int i = 0; i < numPoints; i++) {
                if (i == currentNode || set.find(i) != set.end())
                    continue;
                long long currentDistance = distance (points[i], points[currentNode]);
                auto distPair = make_pair(currentDistance, i);
                pq.push(distPair);
            }

            while (true) {
                auto toInsert = pq.top();
                pq.pop();
                //cout << "Current node " << toInsert.second << endl;
                if (set.find(toInsert.second) != set.end())
                    continue;
                set.insert(toInsert.second);
                sum += toInsert.first;
                currentNode = toInsert.second;

                break;
            }
        }
        return sum;
    }
};
