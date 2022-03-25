#include <stdio.h>
#define NUM 5
void add(const double *n,const double *m,double *k,int j);
int main(void)
{
    const double n[NUM]={1,2,3,4,5};
    const double m[NUM]={1.1,2.2,3.3,4.4,5.5};
    double k[NUM];
    add(n,m,k,NUM);
    for(int i=0;i<NUM;i++){
        printf("%5g",k[i]);
    }

    return 0;
}
void add(const double *n,const double *m,double *k,int j)
{
    for(int i=0;i<j;i++){
        *(k+i)=*(n+i)+*(m+i);
    }
}