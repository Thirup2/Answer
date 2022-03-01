#include <stdio.h>
int main(void)
{
    //定义值
    int one,two,res;

    //获取值
    printf("This program computes moduli.\n");
    printf("Enter an integer to serve as the second operand:");
    scanf("%d",&one);
    printf("Now enter the first operand:");
    while(scanf("%d",&two)==1&&two>0){
        res = two % one;
        printf("%d %% %d is %d\n",two,one,res);
        printf("Enter next number for first operand (<=0 to quit):");
    }

    //循环结束
    printf("Done\n");

    //函数返回值
    return 0;
}