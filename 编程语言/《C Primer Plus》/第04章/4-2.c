#include <stdio.h>
#include <string.h>
int main(void)
{
    char name[40];
    printf("请输入您的名字:\n");
    while(scanf("%s",name)==1){
        printf("\"%s\"\n",name);
        printf("\"%20s\"\n",name);
        printf("\"%-20s\"\n",name);
        printf("\"%*s\"\n",strlen(name)+3,name);
        printf("请输入您的名字:\n");
    }

    return 0;
}