/*
https://leetcode.com/problems/search-a-2d-matrix/
*/
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
  int start = 0, end = matrixSize * matrixColSize[0] - 1, mid, row, col, num_col = matrixColSize[0];
  
  while (end >= start) {
    mid = (start + end) >> 1;
    row = mid / num_col;
    col = mid % num_col;
    if (matrix[row][col] == target) {
      return true;
    } else if (target > matrix[row][col]) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return false;
}
