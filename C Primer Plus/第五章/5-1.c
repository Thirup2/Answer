#include <stdio.h>
#define SMH 60
int main(void)
{
    //定义值
    int min_tot;
    int min,hour;

    //获取值
    printf("请输入总的分钟数(<=0 to quit):");
    while(scanf("%d",&min_tot)==1&&min_tot>0){
        min=min_tot%SMH;
        hour=min_tot/SMH;
        printf("%d分钟 = %d小时%d分钟\n",min_tot,hour,min);
        printf("请输入下一个总分钟数(<=0 to quit):");
    }

    //函数返回值
    return 0;
}