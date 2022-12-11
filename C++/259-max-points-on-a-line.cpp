/*
https://leetcode.com/problems/max-points-on-a-line/
*/
class Solution {

    int gcd (int a, int b) {
        a = abs(a);
        b = abs(b);
        if (a > b) {
            swap(a, b);
        }
        while (b % a != 0) {
            int tmp = b % a;
            b = a;
            a = tmp;
        }
        return a;
    }

    bool sameline(int dx1, int dy1, int dx2, int dy2) {
        int div;

        if (dx1 == 0 && dx2 == 0)
            return true;
        if (dy1 == 0 && dy2 == 0)
            return true;

        if (dx1 == 0 || dx2 == 0)
            return false;
        if (dy1 == 0 || dy2 == 0)
            return false;

        div = gcd (dx1, dy1);
        dy1 /= div;
        dx1 /= div;
        div = gcd (dx2, dy2);
        dy2 /= div;
        dx2 /= div;

        return dx1 == dx2 && dy1 == dy2;    
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int max_points = 0;
        int dx1, dy1, dx2, dy2;

        if (n < 3)
            return n;

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int count = 0;
                dy1 = points[j][1] - points[i][1];
                dx1 = points[j][0] - points[i][0];
                for (int k = 0; k < n; k++) {
                    if (i == k || j == k)
                        continue;
                    dy2 = points[k][1] - points[i][1];
                    dx2 = points[k][0] - points[i][0];
                    if (sameline(dx1, dy1, dx2, dy2))
                        count++;
                }
                if (count)
                    max_points = max (max_points, count + 2);
            }
        }
        if (max_points == 0)
            return 2;
        return max_points;
    }
};
