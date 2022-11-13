/*
https://www.geeksforgeeks.org/minimum-maximum-values-expression/
*/
#include <iostream>
#include <string>
#include<algorithm>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>
using std::cout;
using std::string;
using std::endl;
using std::vector;
using std::max;


bool isOperator(char op)
{
    return (op == '+' || op == '*');
}
 
// method prints minimum and maximum value
// obtainable from an expression
void printMinAndMaxValueOfExp(string exp)
{
    vector<int> num;
    vector<char> opr;
    string tmp = "";
 
    //  store operator and numbers in different vectors
    for (int i = 0; i < exp.length(); i++)
    {
        if (isOperator(exp[i]))
        {
            opr.push_back(exp[i]);
            num.push_back(atoi(tmp.c_str()));
            tmp = "";
        }
        else
        {
            tmp += exp[i];
        }
    }
    //  storing last number in vector
    num.push_back(atoi(tmp.c_str()));
 
    int len = num.size();
    int minVal[len][len];
    int maxVal[len][len];
 
    //  initializing minval and maxval 2D array
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            minVal[i][j] = INT_MAX;
            maxVal[i][j] = 0;
 
            //  initializing main diagonal by num values
            if (i == j)
                minVal[i][j] = maxVal[i][j] = num[i];
        }
    }
 
    // looping similar to matrix chain multiplication
    // and updating both 2D arrays
    for (int L = 2; L <= len; L++)
    {
        for (int i = 0; i < len - L + 1; i++)
        {
            int j = i + L - 1;
            for (int k = i; k < j; k++)
            {
                int minTmp = 0, maxTmp = 0;
 
                // if current operator is '+', updating tmp
                // variable by addition
                if(opr[k] == '+')
                {
                    minTmp = minVal[i][k] + minVal[k + 1][j];
                    maxTmp = maxVal[i][k] + maxVal[k + 1][j];
                }
 
                // if current operator is '*', updating tmp
                // variable by multiplication
                else if(opr[k] == '*')
                {
                    minTmp = minVal[i][k] * minVal[k + 1][j];
                    maxTmp = maxVal[i][k] * maxVal[k + 1][j];
                }
 
                //  updating array values by tmp variables
                if (minTmp < minVal[i][j])
                    minVal[i][j] = minTmp;
                if (maxTmp > maxVal[i][j])
                    maxVal[i][j] = maxTmp;
            }
        }
    }
 
    //  last element of first row will store the result
    cout << "Minimum value : " << minVal[0][len - 1]
         << ", Maximum value : " << maxVal[0][len - 1];
}

int eval (int a, char op, int b) {
  return (op == '+') ? a + b : a * b;
}

int max_value(string s) {
  vector<int> operands;
  vector<char> operators;
  
  for (int i = 0, start = 0; i < s.length(); i++) {
    if (!isdigit(s[i])) {
      operands.push_back(atoi(s.substr(start, i - start).c_str()));
      operators.push_back(s[i]);
      start = i + 1;
    } else if (i == s.length() - 1) {
      operands.push_back(atoi(s.substr(start).c_str()));
    }
  }
  
  int n = operands.size();
  vector<vector<int>> dp(n);
  
  for (auto &e : dp)
    e.resize(n);

    
  for (int i = 0; i < n; i++) {
    dp[i][i] = operands[i];
  }
  
  for (int m = 1; m < n; m++) {
    for (int i = 0, j = m; j < n; i++, j++) {
      dp[i][j] = INT_MIN;
      for (int k = i, m = i + 1; k < j; k++, m++) {
        int e = eval (dp[i][k], operators[k], dp[m][j]);
	dp[i][j] = max(dp[i][j], e);
      }      
    } 
  }   
  
  return dp[0][n-1];
}

int main() {
  string s = "3+3*5+5+5*6+4+6*7+2";
  int res = max_value (s);
  cout << "My result = " << res << endl;
  printMinAndMaxValueOfExp(s);
}
