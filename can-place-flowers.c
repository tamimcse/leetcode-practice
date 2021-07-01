/*
https://leetcode.com/problems/can-place-flowers/
*/
bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n){
  int count = 0, i;
  
  for (i = 0; i < flowerbedSize;) {
    if (flowerbed[i]) {
      i += 2;
      continue;
    }
    if (i + 1 == flowerbedSize || (i + 1 < flowerbedSize && !flowerbed[i+1])) {
      count++;
      i += 2;
    } else {
      i++;
    }
  }
  
  return n <= count;
}
