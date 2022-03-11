#include <stdio.h>
#define NUM 10
void tran(double*,int);
int main(void)
{
    double source[NUM]={1,2,3,4,5,6,7,8,9,10};
    tran(source,NUM);
    for(int i=0;i<NUM;i++){
        printf("%5g",source[i]);
    }

    return 0;
}
void tran(double *source,int n)
{
    double mid=*source;
    for(int i=0;i<n/2;i++){
        source[i]=source[n-i-1];
        source[n-i-1]=mid;
        mid=source[i+1];
    }
}