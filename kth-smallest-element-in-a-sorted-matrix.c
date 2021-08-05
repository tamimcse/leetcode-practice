/*
https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

Very interesting problem!
*/
struct index {
  int row;
  int col;
};

void push_up (struct index *heap, int heap_len, int child_idx, int** matrix)
{
  if (!child_idx)
    return;
  int parent_idx = (child_idx - 1) >> 1;
  int left_idx = (parent_idx << 1) + 1, right_idx = (parent_idx << 1) + 2;
  int smallest_child_idx = -1;
  struct index tmp;
  
  if (left_idx < heap_len)
    smallest_child_idx = left_idx;
  
  if (right_idx < heap_len && 
      matrix[heap[left_idx].row][heap[left_idx].col] > matrix[heap[right_idx].row][heap[right_idx].col])
    smallest_child_idx = right_idx;
  
  if (smallest_child_idx >= 0 &&
      matrix[heap[parent_idx].row][heap[parent_idx].col] > matrix[heap[smallest_child_idx].row][heap[smallest_child_idx].col]) {
    tmp = heap[parent_idx];
    heap[parent_idx] = heap[smallest_child_idx];
    heap[smallest_child_idx] = tmp;
    push_up (heap, heap_len, parent_idx, matrix);
  }
}

void push_down (struct index *heap, int heap_len, int parent_idx, int** matrix)
{
  int left_idx = (parent_idx << 1) + 1, right_idx = (parent_idx << 1) + 2;
  int smallest_child_idx = -1;
  struct index tmp;
  
  if (left_idx < heap_len)
    smallest_child_idx = left_idx;
  
  if (right_idx < heap_len && matrix[heap[left_idx].row][heap[left_idx].col] > matrix[heap[right_idx].row][heap[right_idx].col])
    smallest_child_idx = right_idx;
  
  if (smallest_child_idx >= 0 &&
      matrix[heap[parent_idx].row][heap[parent_idx].col] > matrix[heap[smallest_child_idx].row][heap[smallest_child_idx].col]) {
    tmp = heap[parent_idx];
    heap[parent_idx] = heap[smallest_child_idx];
    heap[smallest_child_idx] = tmp;
    push_down (heap, heap_len, smallest_child_idx, matrix);
  }
}

void insert (struct index *heap, int *heap_len, struct index to_add, int** matrix)
{
  heap[*heap_len] = to_add;
  (*heap_len)++;
  push_up (heap, *heap_len, *heap_len - 1, matrix);
}

void delete (struct index *heap, int *heap_len, int** matrix)
{
  if (!(*heap_len))
    return;
  heap[0] = heap[*heap_len - 1];
  (*heap_len)--;
  push_down (heap, *heap_len, 0, matrix);
}

int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k){
  int num_row = matrixSize, num_col = matrixSize, count = 0, i, j;
  struct index *heap = (struct index *) malloc (num_row * num_row *
                                                sizeof (*heap));
  int **state = (int **) malloc (num_row * sizeof (*state));
  int heap_len = 0;
  int row, col, res;
  struct index idx;
  
  for (i = 0; i < num_row; i++)
    state[i] = (int *) calloc (num_row, sizeof (int));
  
  idx = (struct index) {0, 0};
  insert (heap, &heap_len, idx, matrix);
  while (count < k) {
    idx = heap[0];
    row = idx.row;
    col = idx.col;
    state[row][col] = 2;
    delete (heap, &heap_len, matrix);
    count++;
    if (col + 1 < num_col && (row == 0 || state[row-1][col+1] == 2)) {
      idx = (struct index) {row, col + 1};
      insert (heap, &heap_len, idx, matrix);
      state[row][col+1] = 1;
    }
    if (row + 1 < num_row && (col == 0 || state[row + 1][col - 1] == 2)) {
      idx = (struct index) {row + 1, col};
      insert (heap, &heap_len, idx, matrix);
      state[row+1][col] = 1;
    }
  }
  return matrix[row][col];
}
