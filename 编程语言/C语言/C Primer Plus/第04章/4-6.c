#include <stdio.h>
#include <string.h>
int main(void)
{
    char f_name[20];
    char l_name[20];
    printf("请输入你的名字:\n");
    scanf("%s",f_name);
    printf("请输入你的姓:\n");
    scanf("%s",l_name);
    printf("%s %s\n",f_name,l_name);
    printf("%*d %*d\n",strlen(f_name),strlen(f_name),strlen(l_name),strlen(l_name));
    printf("%s %s\n",f_name,l_name);
    printf("%-*d %-*d\n",strlen(f_name),strlen(f_name),strlen(l_name),strlen(l_name));

    return 0;
}