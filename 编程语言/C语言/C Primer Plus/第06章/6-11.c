#include <stdio.h>
#define NUM 8
int main(void)
{
    int som[8];
    printf("请输入8个整数:\n");
    for(int i=0;i<NUM;i++){
        scanf("%d",&som[i]);
    }
    for(int i=NUM-1;i>=0;i--){
        printf("%d ",som[i]);
    }

    return 0;
}