/*
https://leetcode.com/problems/binary-watch/
*/
class Solution {
    #define LEN 10
    
    string time(int arr[]) {
        int hour = 0, min = 0;
        
        for (int i = 0; i < 4; i++) {
            hour += arr[i] * pow (2, i);
        }
        
        for (int i = 4, j = 0; i < 10; i++, j++) {
            min += arr[i] * pow (2, j);
        }
        
        if (min >= 60 || hour >= 12)
            return "";
        
        return to_string(hour) + ":" + ((min <= 9) ? "0" : "") + to_string(min); 
    }
    void readBinaryWatch_inner(int turnedOn, int arr[], int start, vector<string> &res) {
        if (!turnedOn) {
            //cout << time(arr) << endl;
            string s = time(arr);
            if (s != "")
                res.push_back(time(arr));
            return;
        }
        for (int i = start; i < LEN; i++) {
            if (!arr[i]) {
                arr[i] = 1;
                readBinaryWatch_inner (turnedOn - 1, arr, i + 1, res);
                arr[i] = 0;
            } 
        }
    }
public:
    vector<string> readBinaryWatch(int turnedOn) {
        int arr[LEN] = {0};
        vector<string> res;
        readBinaryWatch_inner (turnedOn, arr, 0, res);
        return res;
    }
};
