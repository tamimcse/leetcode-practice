/*
https://leetcode.com/problems/dot-product-of-two-sparse-vectors/

Here, I used runlength encoding. But, there can be simplier solution like 
*/
class SparseVector {
public:
    vector<int> encoded;
    SparseVector(vector<int> &nums) {
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0 && (i == 0 || nums[i-1] != 0)) {
                encoded.push_back(-1);
                encoded.push_back(1);
            } else if (i > 0 && nums[i] == 0 && nums[i-1] == 0) {
                encoded[encoded.size() - 1]++;
            } else {
                encoded.push_back(nums[i]);
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        vector<int> encoded1 = vec.encoded;
        int m = encoded.size(), n = encoded1.size();
        int res = 0;
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (encoded[i] > 0 && encoded1[j] > 0) {
                res += encoded[i] * encoded1[j];
                i++;
                j++;
                continue;
            }
            int a = 0, b = 0;
            if (encoded[i] == -1)
                a = encoded[i + 1];
            if (encoded1[j] == -1)
                b = encoded1[j + 1];
            int to_skip = max (a, b);
            
            int tmp = to_skip;
            while (to_skip > 0) {
                if (encoded[i] == -1) {
                    if (to_skip >= encoded[i+1]) {
                        to_skip -= encoded[i+1]; 
                        i += 2;   
                    } else {
                        encoded[i+1] -= to_skip;
                        break;
                    }
                } else {
                    to_skip--;
                    i++;
                }
            }
            
            to_skip = tmp;
            while (to_skip > 0) {
                if (encoded1[j] == -1) {
                    if (to_skip >= encoded1[j+1]) {
                        to_skip -= encoded1[j+1]; 
                        j += 2;   
                    } else {
                        encoded1[j+1] -= to_skip;
                        break;
                    }
                } else {
                    to_skip--;
                    j++;
                }
            }
        }
        return res;
    }
};
