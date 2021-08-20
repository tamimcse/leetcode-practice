/*
https://leetcode.com/problems/binary-watch/
*/
int hour[4];
int min[6];

int get_hour ()
{
  int i, hour_ = 0;
  
  for (i = 0; i < 4; i++) {
    hour_ = hour_ + (hour[i] << i);
  }
  return hour_;
}

int get_min ()
{
  int i, min_ = 0;
  
  for (i = 0; i < 6; i++) {
    min_ = min_ + (min[i] << i);
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

void backtrack (int num, int min_start, int hour_start, char **res, int *res_cnt)
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

  for (i = hour_start; i < 4; i++) {
    hour[i] = 1;
    if (valid ())
      backtrack (num - 1, min_start, i + 1, res, res_cnt);
    hour[i] = 0;
  }
  for (i = min_start; i < 6; i++) {
    min[i] = 1;
    if (valid ())
      backtrack (num - 1, i + 1, hour_start, res, res_cnt);
    min[i] = 0;
  }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** readBinaryWatch(int turnedOn, int* returnSize){
  char **res = (char **) malloc (2000 * sizeof (*res));
  int res_cnt = 0;
  
  memset (hour, 0, 4 * sizeof (int));
  memset (min, 0, 6 * sizeof (int));
  backtrack (turnedOn, 0, 0, res, &res_cnt);
  *returnSize = res_cnt;
  return res;
}
