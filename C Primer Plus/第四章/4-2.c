#include <stdio.h>
#include <string.h>
int main(void)
{
    //定义值
    char name[40];

    //获取值
    printf("请输入你的姓名:");
    scanf("%s",name);

    //打印值
    printf("\"%s\"\n",name);
    printf("\"%20s\"\n",name);
    printf("\"%-20s\"\n",name);
    printf("\"%*s\"\n",strlen(name)+3,name);

    //函数返回值
    return 0;
}