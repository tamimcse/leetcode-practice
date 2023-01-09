/*
https://leetcode.com/problems/remove-k-digits/
*/
class Solution {
public:
    string removeKdigits(string num, int k) {
        for (int i = 0; i < k; i++) {
            while (num.length() > 1 && num[0] == '0')
                num.erase(0, 1);
            int n = num.length();
            if (n <= k - i)
                return "0";
            for (int j = 1; j < n; j++) {
                if (num[j] < num[j-1]) {
                    num.erase(j-1, 1);
                    break;
                } else if (j == n - 1) {
                    num.erase(n - (k - i));
                    return num;
                }
            }
        }
        while (num.length() > 1 && num[0] == '0')
            num.erase(0, 1);
        return num;
    }
};
