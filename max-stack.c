/*
https://leetcode.com/problems/max-stack/

very intersting problem!!!

Design a max stack data structure that supports the stack operations and supports finding the stack's maximum element.

Implement the MaxStack class:

MaxStack() Initializes the stack object.
void push(int x) Pushes element x onto the stack.
int pop() Removes the element on top of the stack and returns it.
int top() Gets the element on the top of the stack without removing it.
int peekMax() Retrieves the maximum element in the stack without removing it.
int popMax() Retrieves the maximum element in the stack and removes it. If there is more than one maximum element, only remove the top-most one.
 

Example 1:

Input
["MaxStack", "push", "push", "push", "top", "popMax", "top", "peekMax", "pop", "top"]
[[], [5], [1], [5], [], [], [], [], [], []]
Output
[null, null, null, null, 5, 5, 1, 5, 1, 5]

Explanation
MaxStack stk = new MaxStack();
stk.push(5);   // [5] the top of the stack and the maximum number is 5.
stk.push(1);   // [5, 1] the top of the stack is 1, but the maximum is 5.
stk.push(5);   // [5, 1, 5] the top of the stack is 5, which is also the maximum, because it is the top most one.
stk.top();     // return 5, [5, 1, 5] the stack did not change.
stk.popMax();  // return 5, [5, 1] the stack is changed now, and the top is different from the max.
stk.top();     // return 1, [5, 1] the stack did not change.
stk.peekMax(); // return 5, [5, 1] the stack did not change.
stk.pop();     // return 1, [5] the top of the stack and the max element is now 5.
stk.top();     // return 5, [5] the stack did not change.
 

Constraints:

-107 <= x <= 107
At most 104 calls will be made to push, pop, top, peekMax, and popMax.
There will be at least one element in the stack when pop, top, peekMax, or popMax is called.

*/


int max (int a, int b)
{
  return a > b ? a : b;
}

typedef struct {
    int arr[4000];
    int max[4000];
    int start;
} MaxStack;

/** initialize your data structure here. */

MaxStack* maxStackCreate() {
  MaxStack *s = (MaxStack *) malloc (sizeof (*s));
  s->start = 0;
  return s;
}

void maxStackPush(MaxStack* obj, int x) {
  obj->arr[obj->start] = x;
  if (obj->start)
    obj->max[obj->start] = max (x, obj->max[obj->start - 1]);
  else
    obj->max[obj->start] = x;
  obj->start++;
}

int maxStackPop(MaxStack* obj) {
  obj->start--;
  return obj->arr[obj->start];
}

int maxStackTop(MaxStack* obj) {
  return obj->arr[obj->start - 1];
}

int maxStackPeekMax(MaxStack* obj) {
  return obj->max[obj->start - 1];
}

int maxStackPopMax(MaxStack* obj) {
  int i, j;
  int to_return = obj->max[obj->start-1];
  int tmp_arr[4000];
  
  for (i = 0, j = obj->start-1; obj->arr[j] != to_return; i++, j--) {
    tmp_arr[i] = obj->arr[j];
  }
  
  --i;
  for (; i >= 0; i--, j++) {
    obj->arr[j] = tmp_arr[i];
    if (j > 0)
      obj->max[j] = max (obj->max[j - 1], tmp_arr[i]);
    else
      obj->max[j] = tmp_arr[i];
  }
  obj->start--;
  return to_return;
}

void maxStackFree(MaxStack* obj) {
  free (obj);
}

/**
 * Your MaxStack struct will be instantiated and called as such:
 * MaxStack* obj = maxStackCreate();
 * maxStackPush(obj, x);
 
 * int param_2 = maxStackPop(obj);
 
 * int param_3 = maxStackTop(obj);
 
 * int param_4 = maxStackPeekMax(obj);
 
 * int param_5 = maxStackPopMax(obj);
 
 * maxStackFree(obj);
*/
