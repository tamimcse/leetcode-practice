/*
https://leetcode.com/problems/binary-watch/

Very very very very interesting problem!!!!!!
*/
int led[10];

int get_hour ()
{
  int i, hour_ = 0;
  
  for (i = 0; i < 4; i++) {
    hour_ = hour_ + (led[i] << i);
  }
  return hour_;
}

int get_min ()
{
  int i, min_ = 0;
  
  for (i = 0; i < 6; i++) {
    min_ = min_ + (led[4 + i] << i);
  }
  return min_;
}

bool valid ()
{
  int i, min_ = 0, hour_ = 0;
  
  hour_ = get_hour ();
  if (hour_ >= 12)
    return false;
  
  min_ = get_min ();
  if (min_ >= 60)
    return false;
  return true;
}

void backtrack (int num, int start, char **res, int *res_cnt)
{
  int i, hour_, min_;
  char *str = (char *) calloc (6, sizeof (char));
  //printf ("backtrack %d \n", num);
  
  if (!num) {
    hour_ = get_hour ();
    min_ = get_min ();
    sprintf (str, "%d:%02d", hour_, min_);
    res[(*res_cnt)++] = str;
    return;
  }

  for (i = start; i < 10; i++) {
    led[i] = 1;
    if (valid ())
      backtrack (num - 1, i + 1, res, res_cnt);
    led[i] = 0;
  }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** readBinaryWatch(int turnedOn, int* returnSize){
  char **res = (char **) malloc (2000 * sizeof (*res));
  int res_cnt = 0;
  
  memset (led, 0, 10 * sizeof (int));
  backtrack (turnedOn, 0, res, &res_cnt);
  *returnSize = res_cnt;
  return res;
}
