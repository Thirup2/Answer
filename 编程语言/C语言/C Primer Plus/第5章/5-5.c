#include <stdio.h>
int main(void)
{
    //定义值
    int day,count;
    int sum;

    //获取值
    printf("请输入赚的天数(<=0 to quit):");
    while(scanf("%d",&day)==1&&day>0){
        for(count=0,sum=0;count<=day;count++){
            sum+=count;
        }
        printf("一共是:%d元\n",sum);
        printf("请输入另一个赚钱天数(<=0 to quit):");
    }

    //函数返回值
    return 0;
}