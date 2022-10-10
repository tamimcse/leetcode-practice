/*
https://leetcode.com/problems/valid-mountain-array/
*/
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3)
            return false;
        bool top_found = false;
        
        if (arr[1] <= arr[0])
            return false;
        for (int i = 2; i < arr.size(); i++) {
            if (arr[i] == arr[i-1])
                return false;
            if (!top_found) {
                if (arr[i] < arr[i-1])
                    top_found = true;
            } else {
                if (arr[i] >= arr[i-1])
                    return false;
            }    
        }
        return top_found && arr.back() < arr[arr.size() - 2];
    }
};
