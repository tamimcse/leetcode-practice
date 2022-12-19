/*
https://leetcode.com/problems/count-of-range-sum/
*/


/*********It was getting TLE********************************/
class Solution {
    void countRangeSum (vector<long long> &prefix_sum, int start, int end, 
                        int lower, int upper, int &count) {
        int n = prefix_sum.size();
        int mid = (start + end) >> 1;

        if (start == end)
            return;
            
        countRangeSum(prefix_sum, start, mid, lower, upper, count);
        countRangeSum(prefix_sum, mid + 1, end, lower, upper, count);
        
        for (int i = start; i <= mid; i++) {
            int j = mid + 1;
            int k = end;
            while (j <= end) {
                if ((long long)prefix_sum[j] - prefix_sum[i] >= lower)
                    break;
                else
                    j++;    
            }
            
            while (k >= mid +1) {
                if ((long long)prefix_sum[k] - prefix_sum[i] <= upper)
                    break;
                else
                    k--;    
            }
            if (k >= j) {
                count += k - j + 1;
            }
        }
        inplace_merge(prefix_sum.begin() + start, prefix_sum.begin() + mid + 1,
                      prefix_sum.begin() + end + 1);
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> prefix_sum(n);
        int running_sum = 0;
        int count = 0;

        prefix_sum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix_sum[i] = prefix_sum[i-1] + nums[i];
        }

        for (int i = 0; i < n; i++) {
            if (prefix_sum[i] >= lower && prefix_sum[i] <= upper)
                count++;
        }

        countRangeSum(prefix_sum, 0, n-1, lower, upper, count);

        return count;
    }
};



/********I refnied it further. It still gets TLE *********/
class Solution {
    void countRangeSum (vector<long long> &prefix_sum, int start, int end, 
                        int lower, int upper, int &count) {
        int n = prefix_sum.size();
        int mid = (start + end) >> 1;

        if (start == end)
            return;
            
        countRangeSum(prefix_sum, start, mid, lower, upper, count);
        countRangeSum(prefix_sum, mid + 1, end, lower, upper, count);
        
        int j = mid + 1;
        for (int i = start; i <= mid; i++) {
            while (j <= end) {
                if ((long long)prefix_sum[j] - prefix_sum[i] >= lower)
                    break;
                else
                    j++;
            }
            int k = j;
            while (k <= end && (long long)prefix_sum[k] - prefix_sum[i] <= upper) {
                count++;
                k++;
            }
        }
        inplace_merge(prefix_sum.begin() + start, prefix_sum.begin() + mid + 1,
                      prefix_sum.begin() + end + 1);
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> prefix_sum(n);
        int running_sum = 0;
        int count = 0;

        prefix_sum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix_sum[i] = prefix_sum[i-1] + nums[i];
        }

        for (int i = 0; i < n; i++) {
            if (prefix_sum[i] >= lower && prefix_sum[i] <= upper)
                count++;
        }

        countRangeSum(prefix_sum, 0, n-1, lower, upper, count);

        return count;
    }
};
