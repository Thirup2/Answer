#include <stdio.h>
#define O "one"
#define T "two"
#define TH "three"
void one_three(void);       //打印一到三,二用另一个函数打印
void two(void);             //打印二
int main(void)
{
    //打印
    printf("starting now:\n");
    one_three();
    printf("done!\n");

    //函数返回值
    return 0;
}
void one_three(void)
{
    printf("one\n");
    two();
    printf("three\n");
}
void two(void)
{
    printf("two\n");
}