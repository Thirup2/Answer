#include <stdio.h>
#define SE 7
#define TH 3
void copy(double *,double *,int);
int main(void)
{
    double source[SE]={1,2,3,4,5.5,6,7.7};
    double target[TH];
    copy(source,target,TH);
    for(int i=0;i<TH;i++){
        printf("target[%d] = %g\n",i,target[i]);
    }

    return 0;
}
void copy(double *source,double *target,int n)
{
    for(int i=0;i<n;i++){
        *(target+i)=*(source+i+2);
    }
}