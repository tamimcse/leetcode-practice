/*
https://leetcode.com/problems/number-of-days-between-two-dates/
*/    
class Solution {
    bool is_leapyear(int year) {
        if (year % 100 == 0)
            return year % 400 == 0;
        return (year % 4 == 0);
    }
    
    int since_epoc (string date) {
        int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int year = stoi(date.substr(0, 4));
        int mon = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8));
        
        int i = 1970;
        while (year > i) {
            day += is_leapyear(i) ? 366 : 365;
            i++;
        }
        for (int i = 1; i <= mon - 1; i++) {
            day += months[i];
            if (i == 2 && is_leapyear(year))
                day++;
        }
        return day;
    }
public:
    int daysBetweenDates(string date1, string date2) {
        //cout << since_epoc (date2);
        return abs(since_epoc (date2) -  since_epoc (date1));
    }
};
