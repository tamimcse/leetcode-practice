/*
https://leetcode.com/problems/design-hit-counter/

Design a hit counter which counts the number of hits received in the past 5 minutes (i.e., the past 300 seconds).

Your system should accept a timestamp parameter (in seconds granularity), and you may assume that calls are being made to the system in chronological order (i.e., timestamp is monotonically increasing). Several hits may arrive roughly at the same time.

Implement the HitCounter class:

HitCounter() Initializes the object of the hit counter system.
void hit(int timestamp) Records a hit that happened at timestamp (in seconds). Several hits may happen at the same timestamp.
int getHits(int timestamp) Returns the number of hits in the past 5 minutes from timestamp (i.e., the past 300 seconds).
*/
typedef struct {
  int circ_arr[300];
  int end;
  int last_ts;
  int total;
} HitCounter;

/** Initialize your data structure here. */

HitCounter* hitCounterCreate() {
  HitCounter *hc = (HitCounter *) calloc (1, sizeof (*hc));
  return hc;
}

/** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
void hitCounterHit(HitCounter* obj, int timestamp) {
  int ts_idx = (timestamp - 1) % 300; 
  
  int i, to_remove = 0;
  if ((timestamp - obj->last_ts) >= 300 ) {
    for (i = 0; i < 300; i++) {
      obj->circ_arr[i] = 0;
    }
    obj->total = 1;
    obj->circ_arr[ts_idx] = 1;
    obj->end = (ts_idx + 1) % 300;
  } else if ((ts_idx + 1) % 300 != obj->end) {
    for (i = obj->end;; i = (i + 1) % 300) {
      to_remove += obj->circ_arr[i];
      obj->circ_arr[i] = 0;
      if (i == ts_idx)
        break;
    }    
    obj->total = obj->total - to_remove + 1;
    obj->circ_arr[ts_idx] = 1;
    obj->end = (ts_idx + 1) % 300;
  } else {
    obj->circ_arr[ts_idx]++;
    obj->total++;
  }

  obj->last_ts = timestamp;
}

/** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
int hitCounterGetHits(HitCounter* obj, int timestamp) {
  int ts_idx = (timestamp - 1) % 300;
  int i, to_remove = 0;
  
  if ((timestamp - obj->last_ts) >= 300 ) {
    for (i = 0; i < 300; i++) {
      obj->circ_arr[i] = 0;
    }
    obj->total = 0;
    obj->end = 0;
  } else if ((ts_idx + 1) % 300 != obj->end) {
    for (i = obj->end;; i = (i + 1) % 300) {
      to_remove += obj->circ_arr[i];
      obj->circ_arr[i] = 0;
      if (i == ts_idx)
        break;
    }
    obj->total = obj->total - to_remove;
    obj->end = (ts_idx + 1) % 300;
  }
  obj->last_ts = timestamp;
  return obj->total;
}

void hitCounterFree(HitCounter* obj) {
  free (obj);  
}

/**
 * Your HitCounter struct will be instantiated and called as such:
 * HitCounter* obj = hitCounterCreate();
 * hitCounterHit(obj, timestamp);
 
 * int param_2 = hitCounterGetHits(obj, timestamp);
 
 * hitCounterFree(obj);
*/
