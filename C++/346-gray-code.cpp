/*
https://leetcode.com/problems/gray-code/
*/
class Solution {
    int arr[4] = {0, 1, 1, 0};
    int cur_state;
    int num_bits_cur_state;
    
    void next_state (int bitpos) {
        num_bits_cur_state++;
        
        if (pow(2, bitpos) == num_bits_cur_state) {
            cur_state = (cur_state + 1) % 4;
            num_bits_cur_state = 0;
        }
    }
    
    void reset_state() {
        cur_state = 0;
        num_bits_cur_state = 0;        
    }
    
    int cur_bit () {
        return arr[cur_state];
    }
public:
    vector<int> grayCode(int n) {
        int m = pow(2, n);
        vector<int> res(m);
        int bit_to_insert;
        
        reset_state();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                bit_to_insert = cur_bit ();
                res[j] |= (bit_to_insert << i);
                next_state (i);
            }
            reset_state();
        }
        
        return res;
    }
};
