#include <stdio.h>
#include <stdlib.h>
#define SIZE 40
int main(void)
{
    char name[SIZE];
    FILE *fp;
    int ch;
    printf("请输入文件名:");
    scanf("%s",name);
    if((fp=fopen(name,"r"))==NULL){
        printf("文件打开失败!\n");
        exit(EXIT_FAILURE);
    }
    while((ch=getc(fp))!=EOF){
        putchar(ch);
    }

    return 0;
}