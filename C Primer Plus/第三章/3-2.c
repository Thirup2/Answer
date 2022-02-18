#include <stdio.h>
int main(void)
{
    //定义值
    char ch;

    //获取值
    printf("请输入一个ASCII码:");
    scanf("%d",&ch);

    //打印值
    printf("ASCII码:%d\n字符:%c\n",ch,ch);

    //函数返回值
    return 0;
}