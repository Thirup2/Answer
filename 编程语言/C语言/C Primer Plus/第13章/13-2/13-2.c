#include <stdio.h>
#include <stdlib.h>
#define SIZE 512
int main(int argc,char *argv[])
{
    FILE *fp1,*fp2;
    char buff[SIZE];
    if(argc!=3){
        printf("参数1:原始文件名\n参数2:拷贝文件名\n");
        exit(EXIT_FAILURE);
    }
    if((fp1=fopen(argv[1],"r"))==NULL){
        printf("原始文件打开失败\n");
        exit(EXIT_FAILURE);
    }
    if((fp2=fopen(argv[2],"w"))==NULL){
        printf("拷贝文件打开失败\n");
        exit(EXIT_FAILURE);
    }
    size_t bytes;
    while((bytes=fread(buff,sizeof(char),SIZE,fp1))>0){
        fwrite(buff,sizeof(char),bytes,fp2);
    }
    fclose(fp1);
    fclose(fp2);

    return 0;
}