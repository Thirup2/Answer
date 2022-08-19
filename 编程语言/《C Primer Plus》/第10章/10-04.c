#include <stdio.h>
#define NUM 100
int max(double*,int);
int main(void)
{
    double source[NUM]={5,3,88,99,3};
    printf("数组中最大的数的下标是是:%d\n",max(source,NUM));

    return 0;
}
int max(double *source,int n)
{
    int max=*source;
    int max_x=0;
    for(int i=0;i<n;i++){
        if(max<*(source+i)){
            max=*(source+i);
            max_x=i;
        }
    }
    return max_x;
}