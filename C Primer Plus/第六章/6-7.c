#include <stdio.h>
#include <string.h>
int main(void)
{
    char ch[40];
    int i;
    printf("请输入一个单词:");
    scanf("%s",ch);
    i=strlen(ch);
    for(int j=0;j<=i;i--){
        printf("%c",ch[i-1]);
    }

    return 0;
}