#include <stdio.h>
#include <stdlib.h>

int main() {
  srand(0x539);
  for (int i = 0; i <= 20; i++) {
    int var = rand();
    printf("%d\n", var%100+1);
  }
}

//0x52 // 82
//0x3f // 63
//0x1c // 28
