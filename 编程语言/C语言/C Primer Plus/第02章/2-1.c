#include <stdio.h>
#define F_N "唐"
#define L_N "传顺"
int main(void)
{
    //一次printf()打印一行
    printf("%s%s\n",F_N,L_N);

    //一次printf()打印两行
    printf("%s\n%s\n",F_N,L_N);

    //两次printf()打印一行
    printf("%s",F_N);
    printf("%s\n",L_N);

    //函数返回值
    return 0;
}