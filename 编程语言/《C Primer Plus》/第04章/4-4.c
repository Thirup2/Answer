#include <stdio.h>
int main(void)
{
    float height;
    char name[40];
    printf("请输入您的身高和姓名(英寸):\n");
    while(scanf("%f %s",&height,name)==2){
        printf("%s, you are %g feet tall\n",name,height/12);
        printf("请输入您的身高和姓名(英寸):\n");
    }

    return 0;
}