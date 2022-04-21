#include <stdio.h>
#include <string.h>
#define SIZE 128
int main(void)
{
    char pre[SIZE];
    char aft[SIZE]={'\0'};
    int ISNOT=1;
    while(gets(pre)!=NULL&&pre[0]!='\n'){
        if(strcmp(pre,aft)!=0){
            ISNOT=1;
        }
        if(strcmp(pre,aft)==0&&ISNOT==1){
            printf("%s\n",pre);
            ISNOT=0;
        }
        for(int i=0;i<SIZE;i++){
            aft[i]=pre[i];
        }
    }

    return 0;
}