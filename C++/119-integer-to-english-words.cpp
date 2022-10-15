/*
https://leetcode.com/problems/integer-to-english-words/
*/
class Solution {
public:
    string numberToWords(int num) {
        string res;
        
        if (!num)
            return "Zero";

        int bil = num / 1000000000;
        if (bil)
            res = numberToWords(bil) + " Billion";
        num = num % 1000000000;
        
        int mil = num / 1000000;
        if (mil) {
            if (!res.empty())
                res += " ";
            res += numberToWords(mil) + " Million";
        }
        num = num % 1000000;
        
        int thousand = num / 1000;
        if (thousand) {
            if (!res.empty())
                res += " ";
            res += numberToWords(thousand) + " Thousand";
        }    
        num = num % 1000;
        
        int hundred = num / 100;
        if (hundred) {
            if (!res.empty())
                res += " ";
            res += numberToWords(hundred) + " Hundred";
        }
        num = num % 100;
        
        string ten_str, one_str;
        int ten = num / 10;
        int one = num % 10;
        switch (ten) {
            case 2: 
                ten_str = "Twenty";
                break;
            case 3: 
                ten_str = "Thirty";
                break;
            case 4: 
                ten_str = "Forty";
                break;
            case 5: 
                ten_str = "Fifty";
                break;
            case 6: 
                ten_str = "Sixty";
                break;
            case 7: 
                ten_str = "Seventy";
                break;
            case 8: 
                ten_str = "Eighty";
                break;
            case 9: 
                ten_str = "Ninety";
                break;
        }

        switch (one) {
            case 1: 
                one_str = "One";
                break;
            case 2: 
                one_str = "Two";
                break;
            case 3: 
                one_str = "Three";
                break;
            case 4: 
                one_str = "Four";
                break;
            case 5: 
                one_str = "Five";
                break;
            case 6: 
                one_str = "Six";
                break;
            case 7: 
                one_str = "Seven";
                break;
            case 8: 
                one_str = "Eight";
                break;
            case 9: 
                one_str = "Nine";
                break;
        }

        
        if (num && !res.empty())
                res += " ";
        
        string last_str;
        if (num == 10)
            last_str = "Ten";
        else if (num == 11)
            last_str = "Eleven";
        else if (num == 12)
            last_str = "Twelve";
        else if (num == 13)
            last_str = "Thirteen";
        else if (num == 14)
            last_str = "Fourteen";
        else if (num == 15)
            last_str = "Fifteen";
        else if (num == 16)
            last_str = "Sixteen";
        else if (num == 17)
            last_str = "Seventeen";
        else if (num == 18)
            last_str = "Eighteen";
        else if (num == 19)
            last_str = "Nineteen";
        else {
            if (ten) {
                last_str = ten_str;
                if (one) {
                    last_str += " " + one_str;
                }
            } else {
                last_str = one_str;
            }
        }
        
        res += last_str;
        return res;
    }
};
