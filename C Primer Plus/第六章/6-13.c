#include <stdio.h>
#define NUM 8
int main(void)
{
    int two[NUM];
    two[0]=1;
    for(int i=1;i<=NUM;i++){
        two[i]=two[i-1]*2;
    }
    int i=0;
    do{
        printf("2^%d = %d\n",i,two[i]);
        i++;
    }while(i<NUM);

    return 0;
}