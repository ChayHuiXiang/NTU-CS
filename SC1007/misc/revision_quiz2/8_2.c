#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

//memory
int *r;

int cr_recursive(int *p, int n)
{
    //write your code here
    int max = 0;
    for (int i = 1; i<= n; i++) {
      int max_r = cr_recursive(p, n-i);
      int price_i = p[i];
      int total = max_r + price_i;

      max = total > max ? total : max;
    }

    return max;
}

int cr_top_down_dp(int *p, int n)
{
    //write your code here
    int max = 0;
    for (int i = 1; i<= n; i++) {
      int max_r;
      if (r[n-i] != -1) {
        max_r = r[n-i];
      } else {
        max_r = cr_top_down_dp(p, n-i);
      }
      int price_i = p[i];
      int total = max_r + price_i;
      max = total > max ? total : max;
    }
    r[n] = max;
    return r[n];
}

int cr_bottom_up_dp(int *p, int n)
{
    //write your code here

    int small, large;

    for (int i = 0; i<= n; i++) {
      int max = 0;
      for (int j = 1; j <= i; j++) {
        int max_r = r[i-j];
        int price_i = p[j];
        int total = max_r + price_i;
        if (total > max && i == n) {
          large = i-j;
          small = j;
        }
        max = total > max ? total : max;
      }
      r[i] = max;
    }

    printf("Small: %d | Large: %d\n", small, large);

    return r[n];
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
