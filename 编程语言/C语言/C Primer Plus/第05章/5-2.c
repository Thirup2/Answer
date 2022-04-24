#include <stdio.h>
#define PRINUM 10
int main(void)
{
    int a;
    printf("请输入一个整数,我将打印它及它之后的10个整数:\n");
    while(scanf("%d",&a)==1){
        for(int i=a;i<=a+10;i++){
            printf("%d ",i);
        }
        printf("\n");
        printf("请输入一个整数,我将打印它及它之后的10个整数:\n");
    }

    return 0;
}