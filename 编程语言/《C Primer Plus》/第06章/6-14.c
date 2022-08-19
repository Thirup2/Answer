#include <stdio.h>
#define NUM 8
int main(void)
{
    double some1[NUM];
    double some2[NUM];
    printf("请输入8个整数");
    for(int i=0;i<NUM;i++){
        scanf("%lf",&some1[i]);
    }
    some2[0]=some1[0];
    for(int i=1;i<NUM;i++){
        some2[i]=some2[i-1]+some1[i];
    }
    for(int i=0;i<NUM;i++){
        printf("%-10lf",some1[i]);
    }
    printf("\n");
    for(int i=0;i<NUM;i++){
        printf("%-10lf",some2[i]);
    }

    return 0;
}