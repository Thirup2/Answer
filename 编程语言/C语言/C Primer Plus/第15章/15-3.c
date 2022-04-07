#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
int switch_count(int n);
int main(int argc,char *argv[])
{
    if(argc!=2){
        printf("Usage:%s numerical.\n",argv[0]);
        exit(EXIT_FAILURE);
    }
    int i=atoi(argv[1]);
    printf("The switch bit of %d is %d.\n",i,switch_count(i));
    return 0;
}
int switch_count(int n)
{
    const static int size=CHAR_BIT*sizeof(int);
    int sum=0;
    for(int i=0;i<size;i++){
        if(n&1){
            sum++;
        }
        n>>=1;
    }
    return sum;
}