/*
https://leetcode.com/problems/design-hashset/
*/

#define SIZE 1000001

typedef struct {
  char *hash;    
} MyHashSet;

/** Initialize your data structure here. */

MyHashSet* myHashSetCreate() {
  MyHashSet *h = (MyHashSet *) malloc (sizeof (*h));
  h->hash = (char *) calloc (SIZE, sizeof (*(h->hash)));
  return h;
}

void myHashSetAdd(MyHashSet* obj, int key) {
  obj->hash[key] = 1;
}

void myHashSetRemove(MyHashSet* obj, int key) {
  obj->hash[key] = 0;
}

/** Returns true if this set contains the specified element */
bool myHashSetContains(MyHashSet* obj, int key) {
  return obj->hash[key] == 1;
}

void myHashSetFree(MyHashSet* obj) {
  free (obj->hash);
  free (obj);
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 
 * myHashSetRemove(obj, key);
 
 * bool param_3 = myHashSetContains(obj, key);
 
 * myHashSetFree(obj);
*/
