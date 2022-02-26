#include <stdio.h>
#define DPW 7
int main(void)
{
    //定义值
    int days;
    int week,day;

    //获取值
    printf("请输入一个天数(<=0 to quit):");
    while(scanf("%d",&days)==1&&days>0){
        week = days / DPW;
        day = days % DPW;
        printf("%d days are %d weeks, %d days.\n",days,week,day);
        printf("请输入下一个天数(<=0 to quit):");
    }

    //函数返回值
    return 0;
}