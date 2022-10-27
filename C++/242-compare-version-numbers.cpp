/*
https://leetcode.com/problems/compare-version-numbers/
*/
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int pos1 = 0, pos2 = 0, start1 = 0, start2 = 0;
        int rev1, rev2;
        
        do {
            pos1 = version1.find('.', start1);
            pos2 = version2.find('.', start2);
            
            if (pos1 == string::npos) {
                rev1 = atoi(version1.substr(start1).c_str());
            } else {
                rev1 = atoi(version1.substr(start1, pos1 - start1 + 1).c_str());
            }
            
            if (pos2 == string::npos) {
                rev2 = atoi(version2.substr(start2).c_str());
            } else {
                rev2 = atoi(version2.substr(start2, pos2 - start2 + 1).c_str());
            }
            
            if (rev1 < rev2)
                return  -1;
            else if (rev1 > rev2)
                return 1;
            if (pos1 != string::npos)
                start1 = pos1 + 1;
            else
                start1 = version1.length();
            if (pos2 != string::npos)
                start2 = pos2 + 1;
            else
                start2 = version2.length();
        } while (pos1 != string::npos || pos2 != string::npos);
        
        return 0;
    }
};
