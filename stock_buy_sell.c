/*
Stock Buy Sell to Maximize Profit: The cost of a stock on each day is given in an array, find the max profit that you can make by buying and selling in those days. For example, if the given array is {100, 180, 260, 310, 40, 535, 695}, the maximum profit can earned by buying on day 0, selling on day 3. Again buy on day 4 and sell on day 6. If the given array of prices is sorted in decreasing order, then profit cannot be earned at all.
*/
#include <stdio.h>
#include <stdlib.h>

//Hill climbing with memory
int stock_buy_sell (int *arr, int len)
{
  int i, min, max_diff;

  min = arr[0] < arr[1] ? arr[0] : arr[1];
  max_diff = arr[0] < arr[1] ? arr[1] - arr[0] : 0;

  for (i = 2; i < len; i++) {
    if (arr[i] < min)
      min = arr[i];
    else if (arr[i] - min > max_diff)
      max_diff = arr[i] - min;
  }  
  return max_diff;
}

void main ()
{
  int arr[] = {100, 180, 260, 310, 40, 535, 695};
  int len = sizeof (arr) / sizeof (arr[0]);
  
  int profit = stock_buy_sell (arr, len);
  printf ("Profit = %d \n", profit);
}
