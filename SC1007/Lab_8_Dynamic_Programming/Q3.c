#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

//memory
int *r;


int cr_bottom_up_dp_print(int *p, int n)
{
    //write your code here
  r[0] = 0;
  int piece_one;
  int piece_two;

  for (int i = 1; i<=n; i++) {
    int max = INT32_MIN;
    for (int j = 1; j<=i; j++) {
      int rev = r[i-j] + p[j];
      if (rev > max) {
        max = rev;
        if (i == n) {
          piece_one = j;
          piece_two = n-j;
        }
      }
    }
    r[i] = max;
  }

  printf("Length of piece one: %d\n", piece_one < piece_two ? piece_one : piece_two);
  printf("Length of piece two: %d\n", piece_one < piece_two ? piece_two : piece_one);

  return r[n];
}

 
void main ()
{
    int n;      //length of  rod
    int function;
    int i;
    int *p;     //price list
    
    int price_list[10] = {0,1,4,8,9,10,17,17,20,24}; //declare one more value to cover the index 0;
    
    n = sizeof(price_list) / sizeof(int) - 1;
    p = price_list;
    
    
    //allocate the memory array
    r = malloc(sizeof(int) * (n+1));
    
    
    //set all memory elements to -1
    for (i=0; i<=n; i++)
        r[i] = -1;
                
    printf("The maximun value is: %d \n", cr_bottom_up_dp_print(p,n));
}
