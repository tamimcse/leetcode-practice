/*
https://leetcode.com/problems/lru-cache/
*/

struct tuple{
  int key;
  int val;
  struct tuple *next;
};

typedef struct {
  struct tuple **hashmap;
  struct tuple *freq;
  int count;
  int capacity;
  int timestamp;
} LRUCache;

void heapify (struct tuple *freq, int count, int idx)
{
  //printf ("heapifing at index %d \n", idx);
  //push down
  int chield1 = (idx << 1) + 1, chield2 = (idx << 1) + 2, smallest_chield = -1;
  if (chield1 < count)
    smallest_chield = chield1;
  if (chield2 < count && freq[chield2].val < freq[smallest_chield].val)
    smallest_chield = chield2;
  if (smallest_chield >= 0 && freq[smallest_chield].val < freq[idx].val) {
    //printf ("swaping %d %d \n", smallest_chield, idx);
    struct tuple tmp = freq[idx];
    freq[idx] = freq[smallest_chield];
    freq[smallest_chield] = tmp;
    heapify (freq, count, smallest_chield);
  }
  
  //push up
  int parent = (idx - 1) >> 1;
  if (parent >= 0 && freq[parent].val > freq[idx].val) {
    heapify (freq, count, parent);
  }
}

LRUCache* lRUCacheCreate(int capacity) {
  LRUCache *cache = (LRUCache *) malloc (sizeof (*cache));
  cache->hashmap = (struct tuple **) calloc (capacity, sizeof (*(cache->hashmap)));
  cache->freq = (struct tuple *) calloc (capacity, sizeof (*(cache->freq)));
  cache->count = 0;
  cache->capacity = capacity;
  cache->timestamp = 0;
  return cache;
}

int lRUCacheGet(LRUCache* obj, int key) {
  //printf ("getting %d \n", key);
  int i, val = -1;
  int idx = key % obj->capacity;
  struct tuple *chain = obj->hashmap[idx];
  while (chain) {
    if (chain->key == key) {
      val = chain->val;
      break;
    }
    chain = chain->next;
  }
  if (val == -1)
    return -1;
  for (i = 0; i < obj->count; i++) {
    if (obj->freq[i].key == key) {
      obj->freq[i].val = ++(obj->timestamp);
      heapify (obj->freq, obj->count, i);
      break;
    }
  }
  /*for (i = 0; i < obj->count; i++) {
    printf ("%d ", obj->freq[i].key);
  }
  printf ("\n");*/
  return val;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
  //printf ("Putting %d \n", key);
  int i;
  struct tuple *runner;
  int idx = key % obj->capacity;
  struct tuple *chain = obj->hashmap[idx];
  while (chain) {
    if (chain->key == key) {
      chain->val = value;
      for (i = 0; i < obj->count; i++) {
        if (obj->freq[i].key == key) {
          obj->freq[i].val = ++(obj->timestamp);
          heapify (obj->freq, obj->count, i);
          break;
        }
      }
      return;
    }
    chain = chain->next;
  }
  
  //Need to delete LRU
  int key_to_delete = -1;
  if (obj->count == obj->capacity) {
    key_to_delete = obj->freq[0].key;
    obj->freq[0].key = key;
    obj->freq[0].val = ++(obj->timestamp);
    heapify (obj->freq, obj->count, 0);
  } else {
    //insert new element in freq
    obj->freq[obj->count].key = key;
    obj->freq[obj->count].val = ++(obj->timestamp);
    obj->count++;
    heapify (obj->freq, obj->count, obj->count - 1);
  }
  
  //delete from hashmap
  if (key_to_delete != -1) {
    //printf ("deleting %d\n", key_to_delete);
    idx = key_to_delete % obj->capacity;
    if (obj->hashmap[idx]->key == key_to_delete) {
      obj->hashmap[idx] = obj->hashmap[idx]->next;  
    } else {
      struct tuple *prev = obj->hashmap[idx];
      while (prev->next) {
        if (prev->next->key == key_to_delete) {
          prev->next = prev->next->next;
          break;
        }
        prev = prev->next;
      }
    }
  }
  
  //insert new element
  idx = key % obj->capacity;
  runner = obj->hashmap[idx];
  struct tuple *new_tuple = (struct tuple *) malloc (sizeof (*new_tuple));
  new_tuple->key = key;
  new_tuple->val = value;
  new_tuple->next = runner;
  obj->hashmap[idx] = new_tuple;
  
  /*for (i = 0; i < obj->count; i++) {
    printf ("%d ", obj->freq[i].key);
  }
  printf ("\n");*/
}

void lRUCacheFree(LRUCache* obj) {
  free (obj->hashmap);  free (obj);
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/
