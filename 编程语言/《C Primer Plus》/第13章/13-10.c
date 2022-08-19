#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 256
int main(void)
{
    FILE *fp;
    char file_name[40];
    long position;
    char buffer[SIZE];

    printf("请输入文件名：");
    scanf("%s",file_name);
    if((fp=fopen(file_name,"r"))==NULL){
        printf("Can not open %s.\n",file_name);
        exit(EXIT_FAILURE);
    }
    printf("请输入将要读取的地址(q or -1 to quit):");
    while(scanf("%ld",&position)==1&&position>=0){
        fseek(fp,position,SEEK_SET);
        if(fgets(buffer,SIZE,fp)!=NULL){
            printf("Content is : %s",buffer);
        }
        printf("请输入将要读取的位置(q or -1 to quit):");
    }
    fclose(fp);
    return 0;
}