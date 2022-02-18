#include <stdio.h>
void jolly(void);
void deny(void);
int main(void)
{
    //打印前三条消息
    jolly();
    jolly();
    jolly();

    //打印后一条消息
    deny();

    //函数返回值
    return 0;
}
void jolly(void)        //打印前三条消息
{
    printf("For he's a jolly good fellow!\n");
}
void deny(void)         //打印后一条消息
{
    printf("Which nobody can deny!\n");
}