#include <stdio.h>
int main(void)
{
    int count=0;
    char ch;
    while((ch=getchar())!=EOF){
        count++;
    }
    printf("该文件一共有%d个字符",count);

    return 0;
}