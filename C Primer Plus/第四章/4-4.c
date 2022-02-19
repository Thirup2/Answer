#include <stdio.h>
int main(void)
{
    //定义值
    char name[40];
    double height;

    //获取值
    printf("请输入你的姓名:");
    scanf("%s",name);
    printf("%s,现在请输入你的身高(英寸):",name);
    scanf("%lf",&height);

    //打印值
    printf("%s, you are %g feet tall\n",name,height);

    //函数返回值
    return 0;
}