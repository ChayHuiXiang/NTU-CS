#include <stdio.h>

int recurse(int* array, int n) {
    if (array[n] != -1) {
    return array[n];
  } else if (n == 0 || n == 1) {
    array[n] = n;
    return n;
  } else {
    array[n] = recurse(array, n-1) + recurse(array, n-2);
    return array[n];
  }
}

int fib(int n) {

  int array[n+1];

  for (int i = 0; i<=n; i++) {
    array[i] = -1;
  }

  int result = recurse(array, n);
  return result;
}

int main() {
  int n;
  printf("Enter n: ");
  scanf("%d", &n);

  int result = fib(n);
  printf("Result: %d", result);
}
