#include <stdio.h>
#define SIZE1 40
#define SIZE2 10
char *mystrncpy(char *target,char *source,int n);
int main(void)
{
    char source[SIZE1];
    char target[SIZE2+1];
    puts("请输入:");
    while(gets(source)!=NULL){
        puts(mystrncpy(target,source,SIZE2));
        puts("请输入:");
    }

    return 0;
}
char *mystrncpy(char *target,char *source,int n)
{
    for(int i=0;i<n;i++){
        if((source+i)!=NULL){
            *(target+i)=*(source+i);
        }else{
            *(target+i)='\0';
        }
    }
    *(target+n+1)='\0';
    return target;
}