#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

//memory
int *r;

int cr_recursive(int *p, int n)
{
    //write your code here
  if (n == 0) {
    return 0;
  }
  int max = p[1] + cr_recursive(p, n-1);
  for (int i = 2; i <= n; i++) {
    int rev = p[i] + cr_recursive(p, n-i);
    max = max > rev ? max : rev;
  }
  return max;
}

int cr_top_down_dp(int *p, int n)
{
  if (n == 0) return 0;
  int max = INT32_MIN;
  for (int i = 1; i <= n; i++) {
    if (r[n-i] == -1) {
      r[n-i] = cr_top_down_dp(p, n-i);
    }
    int rev = p[i] + r[n-i];
    max = max > rev ? max : rev;
  }
  return max;
    //write your code here
}

int cr_bottom_up_dp(int *p, int n)
{
  r[0] = 0;

  for (int i = 1; i <= n; i++) {
    int max = INT32_MIN;
    for (int j = 1; j <= i; j++) {
      int rev = r[i-j] + p[j];
      max = max < rev ? rev : max;
    }
    r[i] = max;
  }

  return r[n];
    //write your code here
}
 
void main ()
{
    int n;      //length of  rod
    int function;
    int i;
    int *p;     //price list
    
    int price_list[10] = {0,1,5,8,9,10,17,17,20,24}; //declare one more value to cover the index 0;
    
    n = sizeof(price_list) / sizeof(int) - 1;
    p = price_list;
    
    
    //allocate the memory array
    r = malloc(sizeof(int) * (n+1));
    
    printf("Choose a function (1 for recursive, 2 for top-down DP, 3 for bottom-up DP, 0 to stop): \n");
    scanf("%d",&function);
    while (function != 0)
    {
        if (function == 1)
        {
            printf("The maximun value is: %d \n", cr_recursive(p,n));
        }
        else if (function == 2)
        {
            //set all memory elements to -1
            for (i=0; i<=n; i++)
                r[i] = -1;
                
            printf("The maximun value is: %d \n", cr_top_down_dp(p,n));
        }
        else if (function == 3)
        {
            //set all memory elements to -1
            for (i=0; i<=n; i++)
                r[i] = -1;
                
            printf("The maximun value is: %d \n", cr_bottom_up_dp(p,n));
        }
        printf("Choose a function (1 for recursive, 2 for top-down DP, 3 for bottom-up DP, 0 to stop): \n");
        scanf("%d",&function);
    }
}
