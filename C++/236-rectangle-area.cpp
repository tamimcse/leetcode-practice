/*
https://leetcode.com/problems/rectangle-area/
*/
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area = (abs(ax1-ax2) * abs (ay1 - ay2)) +
                    (abs(bx1-bx2) * abs (by1 - by2));
        
        if (bx1 > ax2 || by1 > ay2 || bx2 < ax1 || by2 < ay1) {
            return area;
        }
        
        int ipx1, ipy1, ipx2, ipy2;
        
        ipx1 = max (ax1, bx1);
        ipy1 = max (ay1, by1);
        ipx2 = min (ax2, bx2);
        ipy2 = min (ay2, by2);
        
        return area - abs (ipx1 - ipx2) * abs (ipy1 - ipy2);
    }
};
