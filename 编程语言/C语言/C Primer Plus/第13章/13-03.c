#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 512
int main(void)
{
    char file[SIZE]={0};
    FILE *fp;
    size_t bytes;;
    char name[40];
    printf("请输入文件名:");
    scanf("%s",name);
    while((fp=fopen(name,"r+"))==NULL){
        printf("文件%s打开失败,请重新输入.",name);
        scanf("%s",name);
    }
    while((bytes=fread(file,sizeof(char),SIZE,fp))>0){
        for(int i=0;i<bytes;i++){
            file[i]=toupper(file[i]);
        }
        fseek(fp,0L,SEEK_SET);
        fwrite(file,sizeof(char),bytes,fp);
        fclose(fp);
    }
    //问题1:当文本比SIZE大时,如何循环读入文本,并依次写入
    //问题2:当SIZE>bytes时,将fclose(fp)放在循环体外,会导致被写入文件变成二进制文件

    return 0;
}