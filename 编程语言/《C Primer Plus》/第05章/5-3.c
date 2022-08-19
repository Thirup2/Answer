#include <stdio.h>
#define TRAN 7
int main(void)
{
    int days;
    printf("请输入时间(天数):\n");
    while(scanf("%d",&days)==1&&days>0){
        printf("%d days = %d weeks and %d days\n",days,days/TRAN,days%TRAN);
        printf("请输入时间(天数):\n");
    }

    return 0;
}