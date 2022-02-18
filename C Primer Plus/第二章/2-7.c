#include <stdio.h>
#define SMI "Smile!"
void sm(void);      //打印"Smile!"
int main(void)
{
    //打印
    sm();sm();sm();
    printf("\n");
    sm();sm();
    printf("\n");
    sm();
    printf("\n");

    //函数返回值
    return 0;
}
void sm(void)
{
    printf("%s",SMI);
}