/*
https://www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/

Here I am using extra space
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct elem {
  int data;
  int next_min;
};

struct stack {
  struct elem *arr;
  int size;
  int top;
  int min_idx;
};

struct stack* create_stack (int size)
{
  struct stack *s = (struct stack *) malloc (sizeof (*s));
  s->arr = (struct elem *) calloc (size, sizeof (*(s->arr)));
  s->size = size;
  s->top = 0;
  s->min_idx = -1;
  return s;
}

void push (struct stack *s, int data)
{
  if (s->top >= s->size) {
    struct elem *new_arr = (struct elem *) calloc (s->size * 2, sizeof (*new_arr));
    memcpy (new_arr, s->arr, s->size * sizeof (*new_arr));
    free (s->arr);
    s->arr = new_arr;
    s->size *= 2;
  }
  s->arr[s->top].data = data;
  if (s->min_idx >= 0 && data < s->arr[s->min_idx].data) {
    s->arr[s->top].next_min = s->min_idx;
    s->min_idx = s->top;
  } else if (s->min_idx < 0) {
    s->min_idx = s->top;
    s->arr[s->top].next_min = -1;
  } else {
    s->arr[s->top].next_min = -1;
  }
  s->top++;
}

int pop (struct stack *s)
{
  s->top--;
  if (s->arr[s->top].next_min >= 0)
    s->min_idx = s->arr[s->top].next_min;
  return s->arr[s->top].data;
}

bool is_empty (struct stack *s)
{
  return s->top == 0;
}

int get_min (struct stack *s)
{
  
  return s->min_idx >= 0 ? s->arr[s->min_idx].data : -1;
}

void main ()
{
  struct stack *s = create_stack(5);
  push (s, 3);
  push (s, 5);
  push (s, 2);
  push (s, 4);
  push (s, 1);

  while (!is_empty (s)) {
    printf ("Min = %d \n", get_min(s));
    printf ("Poping %d \n", pop(s));
  }
}

