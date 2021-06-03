/*
https://leetcode.com/problems/validate-ip-address/
*/

bool valid_ipv4 (char * IP)
{
  int i, j, k, sum, num_dot = 0;
  int len = strlen (IP);
  
  for (i = 0, j = 0; i <= len; i++) {
    if (IP[i] == '.' || IP[i] == '\0') {
      num_dot++;
      if (i - j > 3 || i == j)
        return false;
      if (i - j >= 2 && IP[j] == '0')
        return false;
      sum = 0;
      for (k = j; k < i; k++) {
        sum = sum * 10 + (IP[k] - '0');
      }
      if (sum > 255)
        return false;
      j = i + 1;
      continue;
    }
    if (!isdigit(IP[i]))
      return false;
  }
  
  return num_dot == 4;
}

bool valid_ipv6 (char * IP)
{
  int i, j, k, sum, num_dot = 0;
  int len = strlen (IP);
  for (i = 0, j = 0; i <= len; i++) {
    if (IP[i] == ':' || IP[i] == '\0') {
      num_dot++;
      if (i - j > 4 || i == j)
        return false;
      sum = 0;
      for (k = j; k < i; k++) {
        sum = sum * 10 + (IP[k] - '0');
      }
      j = i + 1;
      continue;
    }
    if (!isdigit(IP[i]) &&
        !(IP[i] >= 'a' && IP[i] <= 'f') &&
        !(IP[i] >= 'A' && IP[i] <= 'F'))
      return false;
  } 
  return num_dot == 8;
}

char * validIPAddress(char * IP){
  if (strchr (IP, '.')) {
    return valid_ipv4 (IP) ? "IPv4" : "Neither";
  }
  
  if (strchr (IP, ':')) {
    return valid_ipv6 (IP) ? "IPv6" : "Neither";
  }
  
  return "Neither";
}
