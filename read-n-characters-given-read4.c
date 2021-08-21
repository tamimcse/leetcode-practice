/*
https://leetcode.com/problems/read-n-characters-given-read4/
*/
/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

/**
 * @param buf Destination buffer
 * @param n   Number of characters to read
 * @return    The number of actual characters read
 */
int _read(char* buf, int n) {
    int num, count = 0;
    char *runner = buf;
  
    while (1) {
      num = read4 (runner);
      count += num;
      runner += num;
      if (count >= n) {
        buf[n] = '\0';
        break;
      }
      if (num < 4) {
        buf[count] = '\0';
        break;
      }
    }
    return count;
}
