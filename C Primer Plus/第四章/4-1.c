#include <stdio.h>
int main(void)
{
    //定义值
    char f_name[40],l_name[40];

    //获取值
    printf("请输入你的姓:");
    scanf("%s",f_name);
    printf("OK, 接下来请输入你的名字:");
    scanf("%s",l_name);

    //打印值
    printf("OK,你的名字是:%s%s\n",f_name,l_name);

    //函数返回值
    return 0;
}