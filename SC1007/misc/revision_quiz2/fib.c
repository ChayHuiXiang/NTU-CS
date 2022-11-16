#include <stdio.h>
#include <stdlib.h>

int* t;

int fib(n) {
  if (t[n] != -1) {
    return t[n];
  }

  if (n == 0 || n == 1 || n == 2) {
    t[n] = n;
    return n;
  }

  t[n] = fib(n-1) + fib(n-3);
  return t[n];
}

int main() {
  int n;
  printf("Enter n: ");
  scanf("%d", &n);

  t = (int*)malloc(sizeof(int) * (n+1));
  for (int i = 0; i <= n; i++) {
    t[i] = -1;
  }
  fib(n);

  printf("Solution: %d", t[n]);

  return 0;
}
