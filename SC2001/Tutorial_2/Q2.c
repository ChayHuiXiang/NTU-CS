#include <stdio.h>
#include <stdlib.h>

int arr[10] = {1, 3, 2, 4, 5, 9, 8, 7, 6, 0};

int* solution(int n, int m) {
  int* ans = malloc(2 * sizeof(int));
  int mid = (n+m) / 2;
  if (m - n == 0) {
    ans[0] = arr[m];
    ans[1] = arr[m];
  } else if (m - n == 1) {
    if (arr[m] < arr[n]) {
      ans[0] = arr[m];
      ans[1] = arr[n];  
    } else {
      ans[1] = arr[m];
      ans[0] = arr[n];
    }
  } else {
    int* lVals = solution(n, mid);
    int* rVals = solution(mid + 1, m);
    int lmin = lVals[0];
    int lmax = lVals[1];
    int rmin = rVals[0];
    int rmax = rVals[1];
    if (lmin < rmin) {
      ans[0] = lmin;
    } else {
      ans[0] = rmin;
    }
    if (lmax > rmax) {
      ans[1] = lmax;
    } else {
      ans[1] = rmax;
    }
  }
  return ans;
}

int main() {
  int* ans = solution(0, 9);
  printf("Min: %d, Max: %d", ans[0], ans[1]);
}
