/*
https://www.geeksforgeeks.org/maximum-minimum-values-algebraic-expression/
*/
/*
#include <stdio.h>

int max_algebric_expr (int arr[], int m, int n)
{
  int i, j, sum = 0;

  for (i = 0; i < m + n; i++)
    sum += arr[i];
}

void main ()
{
  int m = 3, n = 2;
  int arr[] = {1, 2, 3, 4, 5};
  int res = 
}
*/
// CPP program to find the maximum
// and minimum values of an Algebraic
// expression of given form
#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
#define MAX 50

int minMaxValues(int arr[], int n, int m)
{
	// Finding sum of array elements
	int sum = 0;
	for (int i = 0; i < (n + m); i++) {
		sum += arr[i];

		// shifting the integers by 50
		// so that they become positive
		arr[i] += 50;
	}

// dp[i][j] represents true if sum
// j can be reachable by choosing
// i numbers
bool dp[MAX+1][MAX * MAX + 1];

	// initialize the dp array to 01
	memset(dp, 0, sizeof(dp));

	dp[0][0] = 1;

	// if dp[i][j] is true, that means
	// it is possible to select i numbers
	// from (n + m) numbers to sum upto j
	for (int i = 0; i < (n + m); i++) {

		// k can be at max n because the
		// left expression has n numbers
		for (int k = min(n, i + 1); k >= 1; k--) {
			for (int j = 0; j < MAX * MAX + 1; j++) {
				if (dp[k - 1][j])
					dp[k][j + arr[i]] = 1;
			}
		}
	}

	int max_value = -INF, min_value = INF;

	for (int i = 0; i < MAX * MAX + 1; i++) {

		// checking if a particular sum
		// can be reachable by choosing
		// n numbers
		if (dp[n][i]) {

			// getting the actual sum as
			// we shifted the numbers by
			/// 50 to avoid negative indexing
			// in array
			int temp = i - 50 * n;
			max_value = max(max_value, temp * (sum - temp));
			min_value = min(min_value, temp * (sum - temp));
		}
	}
	cout << "Maximum Value: " << max_value
		<< "\n"
		<< "Minimum Value: "
		<< min_value << endl;
}

// Driver Code
int main()
{
	int n = 2, m = 2;
	int arr[] = { 1, 2, 3, 4 };
	minMaxValues(arr, n, m);
	return 0;
}

