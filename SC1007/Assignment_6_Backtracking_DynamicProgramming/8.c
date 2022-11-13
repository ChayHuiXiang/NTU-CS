#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int* F;

int top_down_dp(int n)
{
    //write your code here
    if (n == 0 || n == 1 || n == 2) {
        F[n] = n;
        return n;
    }

    int F_minus_one, F_minus_two, F_minus_three;

    if (F[n-1] != -1) {
        F_minus_one = F[n-1];
    } else {
        F_minus_one = top_down_dp(n-1);
    }
    if (F[n-2] != -1) {
        F_minus_two = F[n-2];
    } else {
        F_minus_two = top_down_dp(n-2);
    }
    if (F[n-3] != -1) {
        F_minus_three = F[n-3];
    } else {
        F_minus_three = top_down_dp(n-3);
    }

    F[n] = F_minus_one + 2*F_minus_two - 3*F_minus_three;
    return F[n];
}


 
int main ()
{
    int n;
    int function;
    int i;
    printf("Enter the value of n:\n");
    scanf("%d",&n);

    F = malloc((n+1) * sizeof(int));
    for (int i = 0; i<= n; i++) {
        F[i] = -1;
    }
    
    printf("The value of F(%d) is: %d \n", n, top_down_dp(n));
        
}
