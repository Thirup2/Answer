#include <stdio.h>
#define NUM 100
int max(int*,int);
int main(void)
{
    int source[NUM]={5,3,88,99,3};
    printf("数组中最大的数是:%d\n",max(source,NUM));

    return 0;
}
int max(int *source,int n)
{
    int max=*source;
    for(int i=0;i<n;i++){
        if(max<*(source+i)){
            max=*(source+i);
        }
    }
    return max;
}