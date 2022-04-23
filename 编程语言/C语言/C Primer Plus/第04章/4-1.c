#include <stdio.h>
int main(void)
{
    char f_name[20];
    char l_name[20];
    printf("请输入您的名和姓:\n");
    while(scanf("%s %s",f_name,l_name)==2){
        printf("YourName: %s %s\n",f_name,l_name);
        printf("请输入您的名和姓:\n");
    }

    return 0;
}