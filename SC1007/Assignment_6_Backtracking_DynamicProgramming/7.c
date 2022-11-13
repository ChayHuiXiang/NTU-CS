#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


int bottom_up_dp(int n, int *s, int *v, int C)
{
    //write your code here
    int** M = (int**)malloc((n+1) * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        M[i] = (int*)malloc((C+1) * sizeof(int));
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= C; j++) {
            int i_not_used, i_used;

            if (i-1 < 1) {
                i_not_used = 0;
            } else {
                i_not_used = M[i-1][j];
            }

            if (i-1 < 1 || j - s[i] < 1) {
                if (s[i] <= j) {
                    i_used = v[i];
                } else {
                    i_used = 0;
                }
            } else {
                i_used = M[i-1][j-s[i]] + v[i];
            }

            M[i][j] = i_not_used < i_used ? i_used : i_not_used;

        }
    }

    return M[n][C];
}

 
int main ()
{
    int n,C;
    int function;
    int *s;
    int *v;
    int i,j;
    printf("Enter the number of items n:\n");
    scanf("%d",&n);
    printf("Enter the capacity C:\n");
    scanf("%d",&C);
    s = (int *) malloc(sizeof(int) * (n+1));
    v = (int *) malloc(sizeof(int) * (n+1));
    
    printf("Enter the sizes of items (as a list, separate by spacing:\n");
    for (i=1;i<=n;i++)
        scanf("%d",&s[i]);
        
    printf("Enter the values of items (as a list, separate by spacing:\n");
    for (i=1;i<=n;i++)
        scanf("%d",&v[i]);
    
    printf("The maximum value is: %d \n", bottom_up_dp(n,s,v,C));
        
}
