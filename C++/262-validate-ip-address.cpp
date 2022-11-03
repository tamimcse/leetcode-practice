/*
https://leetcode.com/problems/validate-ip-address/
*/
class Solution {
    bool is_ipv4(string ip) {
        int count = 0, n = ip.length(), end;
        
        for (int i = 0, start = 0; i < n; i++) {
            if (ip[i] == '.' || i == n - 1) {
                if (ip[i] != '.')
                    end = i;
                else
                    end = i - 1;
                
                if (start > end || (end - start + 1 > 1 &&  ip[start] == '0') || 
                    (end - start + 1 > 3)) {
                    return false;
                }
                int val = atoi(ip.substr(start, end - start + 1).c_str());
                if (val > 255)
                    return false;
                start = i + 1;
                count++;
            } else if (!isdigit(ip[i])) {
                return false;
            }
        }

        return count == 4 && ip[n-1] != '.';
    }
    
    bool is_ipv6(string ip) {
        int count = 0, n = ip.length(), end;
        
        for (int i = 0, start = 0; i < n; i++) {
            cout << ip[i];
            if (ip[i] == ':' || i == n - 1) {
                if (ip[i] != ':')
                    end = i;
                else
                    end = i - 1;
                if (start > end || end - start + 1 > 4)
                    return false;
                start = i + 1;
                count++;
            } else if (!isdigit(ip[i]) && 
                       !('A' <= ip[i] && 'F' >= ip[i]) &&
                       !('a' <= ip[i] && 'f' >= ip[i])) {
                return false;
            }
        }
        return count == 8 && ip[n - 1] != ':';
    }
public:
    string validIPAddress(string queryIP) {
        int idx = queryIP.find('.');
        if (idx != string::npos) {
            if (is_ipv4(queryIP))
                return "IPv4";
            else
                return "Neither";
        }
        
        idx = queryIP.find(':');
        if (idx != string::npos) {
            if (is_ipv6(queryIP))
                return "IPv6";
            else
                return "Neither";
        }
        
        return "Neither";
    }
};
