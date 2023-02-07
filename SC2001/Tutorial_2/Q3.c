#include <stdio.h>
#include <stdlib.h>

int arr[8] = {0, 1, 2, 5, 2, 3, 4, 1};

void merge(int n, int m) {
  
}

void mergesort(int n, int m) {
  int mid = (n+m) / 2;
  if (m <= n) return;
  else if (m - n > 1)  {
    mergesort(n, mid);
    mergesort(mid+1, m); 
  }
  merge(n, m);
}
