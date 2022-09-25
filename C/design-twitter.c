/*
https://leetcode.com/problems/design-twitter/
*/

struct tweet {
  int tweetId;
  int timestamp;
  struct tweet *next;
};

struct followee {
  int userId;
  struct followee *next;
};

typedef struct {
  struct tweet* tweets[500];
  struct followee* followee[500];
  int current_ts;
} Twitter;

void push_down (struct tweet **heap, int len, int parent_idx)
{
  int left_idx = (parent_idx << 1) + 1, right_idx = (parent_idx << 1) + 2;
  int largest_child_idx = -1;
  struct tweet *tmp;
  
  if (left_idx < len)
    largest_child_idx = left_idx;
  if (right_idx < len && heap[right_idx]->timestamp > heap[left_idx]->timestamp)
    largest_child_idx = right_idx;
  if (largest_child_idx >= 0 &&
      heap[largest_child_idx]->timestamp > heap[parent_idx]->timestamp) {
    tmp = heap[parent_idx];
    heap[parent_idx] = heap[largest_child_idx];
    heap[largest_child_idx] = tmp;
    push_down (heap, len, largest_child_idx);
  }
}

void push_up (struct tweet **heap, int len, int child_idx)
{
  if (!child_idx)
    return;
  int parent_idx = (child_idx - 1) >> 1;
  int left_idx = (parent_idx << 1) + 1, right_idx = (parent_idx << 1) + 2;
  int largest_child_idx = -1;
  struct tweet *tmp;
  
  if (left_idx < len)
    largest_child_idx = left_idx;
  if (right_idx < len && heap[right_idx]->timestamp > heap[left_idx]->timestamp)
    largest_child_idx = right_idx;
  if (largest_child_idx >= 0 &&
      heap[largest_child_idx]->timestamp > heap[parent_idx]->timestamp) {
    tmp = heap[parent_idx];
    heap[parent_idx] = heap[largest_child_idx];
    heap[largest_child_idx] = tmp;
    push_up (heap, len, parent_idx);
  }
}

void heap_insert (struct tweet **heap, struct tweet *to_insert, int *len)
{
  heap[*len] = to_insert;
  (*len)++;
  push_up (heap, *len, *len - 1);
}

struct tweet* heap_delete (struct tweet **heap, int *len)
{
  struct tweet *ret = heap[0];
  
  if (*len == 0)
    return NULL;
  
  heap[0] = heap[*len - 1];
  (*len)--;
  push_down (heap, *len, 0);
  return ret;
}

/** Initialize your data structure here. */

Twitter* twitterCreate() {
  return (Twitter*) calloc (1, sizeof (Twitter));  
}

/** Compose a new tweet. */
void twitterPostTweet(Twitter* obj, int userId, int tweetId) {
  obj->current_ts++;
  struct tweet *t = (struct tweet *) malloc (sizeof (*t));
  t->tweetId = tweetId;
  t->timestamp = obj->current_ts;
  t->next = obj->tweets[userId];
  obj->tweets[userId] = t;
}

/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
int* twitterGetNewsFeed(Twitter* obj, int userId, int* retSize) {
  struct tweet *heap[500] = {NULL};
  struct followee *runner;
  int heap_len = 0;
  int *res = (int *) malloc (10 * sizeof (int));
  int i;
  struct tweet *ret;
  
  if (obj->tweets[userId])
    heap_insert (heap, obj->tweets[userId], &heap_len);
  runner = obj->followee[userId];
  while (runner) {
    if (obj->tweets[runner->userId])
      heap_insert (heap, obj->tweets[runner->userId], &heap_len);
    runner = runner->next;
  }
  
  for (i = 0; i < 10; i++) {
    ret = heap_delete (heap, &heap_len);
    if (!ret)
      break;
    res[i] = ret->tweetId;
    if (ret->next)
      heap_insert (heap, ret->next, &heap_len);
  }
  
  *retSize = i;
  return res;
}

/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
void twitterFollow(Twitter* obj, int followerId, int followeeId) {
  struct followee *runner = obj->followee[followerId];
  while (runner) {
    if (runner->userId == followeeId)
      return;
    runner = runner->next;
  }
  
  struct followee *f = (struct followee *) malloc (sizeof (*f));
  f->userId = followeeId;
  f->next = obj->followee[followerId];
  obj->followee[followerId] = f;
}

/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
void twitterUnfollow(Twitter* obj, int followerId, int followeeId) {
  struct followee *runner = obj->followee[followerId];
  struct followee *to_delete;
  
  if (!runner)
    return;
  
  if (runner->userId == followeeId) {
    to_delete = obj->followee[followerId];
    obj->followee[followerId] = obj->followee[followerId]->next;
    free (to_delete);
    return;
  }
  
  while (runner->next) {
    if (runner->next->userId == followeeId) {
      to_delete = runner->next;
      runner->next = runner->next->next;
      free (to_delete);
      return;
    }
    runner = runner->next;
  }
}

void twitterFree(Twitter* obj) {
  //TODO: delete all the tweet and followee objects
  free(obj);
}

/**
 * Your Twitter struct will be instantiated and called as such:
 * Twitter* obj = twitterCreate();
 * twitterPostTweet(obj, userId, tweetId);
 
 * int* param_2 = twitterGetNewsFeed(obj, userId, retSize);
 
 * twitterFollow(obj, followerId, followeeId);
 
 * twitterUnfollow(obj, followerId, followeeId);
 
 * twitterFree(obj);
*/
