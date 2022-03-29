#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[])
{
    FILE *fp;
    char ch;
    if(argc<2){
        printf("请输入参数(文件名,空格隔开):");
        exit(EXIT_FAILURE);
    }
    for(int i=1;i<argc;i++){
        if((fp=fopen(argv[i],"r"))==NULL){
            printf("文件%s打开失败\n",argv[i]);
            exit(EXIT_FAILURE);
        }
        printf("\n%s :\n",argv[i]);
        while((ch=getc(fp))!=EOF){
            putc(ch,stdout);
        }
        fclose(fp);
    }

    return 0;
}