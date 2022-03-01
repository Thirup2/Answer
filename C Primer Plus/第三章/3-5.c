#include <stdio.h>
#define SPY 3.156e7     //一年的秒数
int main(void)
{
    //定义值
    int age;
    double seconds;

    //获取值
    printf("请输入你的年龄:");
    scanf("%d",&age);

    //计算值
    seconds = age * SPY;

    //打印值
    printf("你的年龄是:%d\n",age);
    printf("对应的秒数是:%le秒\n",seconds);

    //函数返回值
    return 0;
}