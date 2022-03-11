#include <stdio.h>
#define NUM 5
double cha(double *,int);
int main(void)
{
    double source[NUM]={1,2,3,4,5};
    printf("最大值与最小值的差值是:%g\n",cha(source,NUM));

    return 0;
}
double cha(double *source,int n)
{
    double max=*source;
    double min=*source;
    for(int i=0;i<n;i++){
        if(max<*(source+i)){
            max=*(source+i);
        }
        if(min>*(source+i)){
            min=*(source+i);
        }
    }
    return (max-min);
}