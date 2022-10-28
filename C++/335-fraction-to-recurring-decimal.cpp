/*
https://leetcode.com/problems/fraction-to-recurring-decimal/
*/
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res;
        unordered_map<int, string> hash;
        queue<int> q;
        bool neg = (numerator > 0 && denominator < 0) || 
            (numerator < 0 && denominator > 0);
        numerator = abs(numerator);
        denominator = abs (denominator);
        
        res += to_string((long)numerator/denominator);
        if (numerator % denominator == 0) {
            if (neg) {
                cout << "kya\n";
                string neg_res = "-";
                res = neg_res + res;
            }
            return res;
        }
        
        res += ".";
        long rem = numerator % denominator;
        
        int rep_item = -1;
        while (rem) {
            auto it = hash.find(rem);
            if (it != hash.end()) {
                rep_item = rem;
                break;
            }
            string rhs;
            long quo = rem * 10;
            while (quo < denominator) {
                quo *= 10;
                rhs += "0";
            }
            
            rhs += to_string(quo/denominator);
            hash[rem] = rhs;
            q.push(rem);
            rem = quo % denominator;
        }
        
        while (!q.empty()) {
            if (rep_item == q.front())
                res += "(";
            res += hash[q.front()];
            q.pop();
        }
        
        if (rep_item != -1)
            res += ")";
        
        if (neg) {
            string neg_res = "-";
            res = neg_res + res;
        }
        
        return res;
    }
};
