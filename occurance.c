/*
Count the number of times an integer occurs in a sorted array in less than linear time.
*/

#include <stdio.h>

int find_start_of_the_number (int a[], int start_idx, int end_idx, int to_find)
{
  int i;
  
  i = (start_idx + end_idx) / 2;
  if (to_find > a[i]) {
    return find_start_of_the_number (a, i + 1, end_idx, to_find);
  } else if (to_find < a[i]) {
    return find_start_of_the_number (a, start_idx, i - 1, to_find);
  } else {
    //to_find == a[i]. Now check if this is the start of the number
    if (i == 0 || a[i - 1] != a[i])
      return i;
 
  }
}

int count_num_occurance (int a[], int size, int to_find)
{
  int cout = 0;
  int i = find_start_of_the_number (a, 0, size, to_find);
  if (i >= 0) {
    for (; i < size; i++) {
      if (a[i] == to_find)
        count++
      else
        break;
    }
  }
  printf ("Number of occurance of %d is %d \n", to_find, count);
}

void main ()
{
  int [] a = {2, 2, 4, 5, 6, 6, 6, 7, 9, 9, 9, 11};

}
