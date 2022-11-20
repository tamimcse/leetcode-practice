/*
https://leetcode.com/problems/sort-an-array/

Note that, quicksort is O(n^2), so you will get TLE (details would be found in note). You need to use merge sort. But, for practice, implement using both.
*/


///Quick sort
class Solution {
    void sortArray(vector<int>& nums, int start, int end) {
        if (end <= start)
            return;
        int pivot = nums[start];
        int low = start + 1, high = end;
       
        while (low < high) {
            if (nums[low] < pivot) {
                low++;
            } else if (nums[high] > pivot) {
                high--;
            } else {
                swap (nums[low], nums[high]);
                low++;
                high--;
            }
        }
        if (nums[low] > pivot)
            low--;
        swap (nums[start], nums[low]);
        sortArray (nums, start, low - 1);
        sortArray (nums, low + 1, end);
    }
    
    bool is_sorted (vector<int>& nums) {
        int n = nums.size();
        int i = 1;
        
        for (; i < n; i++) {
            if (nums[i] < nums[i-1])
                break;
        }
        
        return i == n;
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        //check if the array is already sorted. If it's, it will generate so many call.
        if (is_sorted(nums))
            return nums;
        sortArray (nums, 0, nums.size() - 1);
        return nums;      
    }
};


///////Merge sort
class Solution {
    void sortArray(vector<int>& nums, int start, int end) {
        if (start + 1 == end) {
            if (nums[start] > nums[end])
                swap (nums[start], nums[end]);
            return;
        }
        int mid = (start + end) >> 1;
        if (mid > start)
            sortArray (nums, start, mid);
        if (end > mid + 1)
            sortArray (nums, mid + 1, end);
        //merge without using extra space
        for (int i = end; i >= mid + 1; i--) {
            if (nums[i] < nums[mid]) {
                int to_insert = nums[i];
                nums[i] = nums[mid];
                int j = mid - 1;
                while (j >= start && nums[j] > to_insert) {
                    nums[j+1] = nums[j];
                    j--;
                }
                nums[j+1] = to_insert;
            }
        }
    }
    
public:
    vector<int> sortArray(vector<int>& nums) {
        sortArray (nums, 0, nums.size() - 1);
        return nums;
    }
};
