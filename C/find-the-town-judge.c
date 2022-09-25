/*
https://leetcode.com/problems/find-the-town-judge/
*/
int findJudge(int N, int** trust, int trustSize, int* trustColSize){
  int *trustee_cnt = (int *) calloc (N + 1, sizeof (int));
  int *trust_cnt = (int *) calloc (N + 1, sizeof (int));
  int i;
  
  if (N == 1 && trustSize == 0)
    return 1;
  
  for (i = 0; i < trustSize; i++) {
    trust_cnt[trust[i][0]]++;
    trustee_cnt[trust[i][1]]++;
  }
  
  for (i = 0; i < N + 1; i++) {
    if (!trust_cnt[i] && trustee_cnt[i] == N-1)
      return i;
  }
  return -1;
}
