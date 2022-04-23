#include <stdio.h>
#define Sec_Year 3.156e7
int main(void)
{
    int age;
    printf("请输入您的年龄:\n");
    while(scanf("%d",&age)==1){
        printf("%d ages = %g seconds\n",age,age*Sec_Year);
        printf("请输入您的年龄:\n");
    }

    return 0;
}