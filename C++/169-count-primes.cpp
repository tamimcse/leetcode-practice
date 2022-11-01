/*
https://leetcode.com/problems/count-primes/
*/
class Solution {
public:
    int countPrimes(int n) {
        int k = sqrt(n), count = 0;
        int *arr[] = new int[n]();
        
        for (int i = 2; i <= k; i++) {
            m = i + i;
            while (m < n) {
                arr[m] = 1;
                m += i;
            }
        }
        
        for (int i = 2; i <= n - 1; i++) {
            if (!arr[i])
                count++;
        }
        
        return count;
    }
};
