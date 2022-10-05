/*
https://leetcode.com/problems/read-n-characters-given-read4/
*/
class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int ret = 0;
        char tmp[4] = {0};
        int idx = 0;
        
        while (n) {
            int num_read = min (n, 4);
            ret = read4(tmp);
            for (int i = 0; i < min(ret, num_read); i++) {
                buf[idx++] = tmp[i];
            }
            if (ret < num_read)
                break;
            n -= num_read;        
        }
        return idx;
    }
};
