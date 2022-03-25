#include <stdio.h>
#define NUM 26
int main(void)
{
    //定义值
    char ch[26];
    char t;
    int i;

    //赋值
    for(t='a',i=0;i<NUM;i++,t++){
        ch[i]=t;
    }
    for(i=0;i<NUM;i++){
        printf("%c",ch[i]);
    }

    //函数返回值
    return 0;
}