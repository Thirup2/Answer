#include <stdio.h>
#define SWAP 60
int main(void)
{
    int min;
    printf("请输入时间(分钟):\n");
    while(scanf("%d",&min)==1&&min>0){
        printf("%d minutes = %d hours %d minutes\n",min,min/SWAP,min%SWAP);
        printf("请输入时间(分钟):\n");
    }

    return 0;
}