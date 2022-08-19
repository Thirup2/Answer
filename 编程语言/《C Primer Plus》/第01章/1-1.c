#include <stdio.h>
#define SWAP 2.54
int main()
{
    double inch;
    printf("请输入一个英寸值:\n");
    while(scanf("%lf",&inch)==1){
        if(inch<=0){
            printf("您的输入不合理,请重新输入:\n");
            continue;
        }else{
            printf("%g inches = %g cm\n",inch,SWAP*inch);
            printf("请输入下一个值:\n");
            continue;
        }
    }
    printf("bye!\n");

    return 0;
}