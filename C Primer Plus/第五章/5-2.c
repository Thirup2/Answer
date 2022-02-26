#include <stdio.h>
#define TEN 10
int main(void)
{
    //定义值
    int some;

    //获取值
    printf("请输入一个整数:");
    scanf("%d",&some);

    //打印值
    for(int i=some;i<=some+10;i++){
        printf("%d\n",i);
    }

    //函数返回值
    return 0;
}