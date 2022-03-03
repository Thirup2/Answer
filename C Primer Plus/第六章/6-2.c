#include <stdio.h>
#define row 5
#define wtp '$'
int main(void)
{
    //打印
    for(int i=1;i<=row;i++){
        for(int j=1;j<=i;j++){
            printf("%c",wtp);
        }
        printf("\n");
    }

    //函数返回值
    return 0;
}