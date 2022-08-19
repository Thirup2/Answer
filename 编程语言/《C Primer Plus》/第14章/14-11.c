#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define LENGTH 10
void transform(double src[],double tar[],int n,double (*func)(double));
int main(int argc,char *argv[])
{
    double source[LENGTH],target[LENGTH];
    for(int i=0;i<LENGTH;i++){
        source[i]=i;
    }
    printf("The source data is:\n");
    for(int i=0;i<LENGTH;i++){
        printf("%5g",source[i]);
    }
    printf("\n");
    transfor(source,target,LENGTH,sin);
    printf("The target sin data is:\n");
    for(int i=0;i<LENGTH;i++){
        printf("%g  ",target[i]);
    }
    printf("\n");

    return 0;
}
void transform(double src[],double tar[],int n,double (*func)(double)){
    for(int i=0;i<n;++i){
        tar[i]=func(src[i]);
    }
}