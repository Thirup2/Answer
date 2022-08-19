#include <stdio.h>
int SquareSum(int,int);
int main(void)
{
    int m,n;
    printf("Enter lower and upper integer limits:");
    while(scanf("%d %d",&m,&n)==2&&m<n){
        printf("The sums of the squares from %d to %d is %d\n",m*m,n*n,SquareSum(m,n));
        printf("Enter next set of limits:");
    }
    printf("Done\n");

    return 0;
}
int SquareSum(int m,int n)
{
    int sum;
    for(;m<=n;m++){
        sum+=m*m;
    }
    return sum;
}