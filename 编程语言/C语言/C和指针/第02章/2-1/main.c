#include <stdio.h>
#include <stdlib.h>
int increment(int num);
int negate(int num);
int main(void)
{
    printf("此处是increment函数打印区域:\n");
    printf("increment(10) = %d\n",increment(10));
    printf("increment(0) = %d\n",increment(0));
    printf("increment(-10) = %d\n\n",increment(-10));
    printf("此处是negate函数打印区域:\n");
    printf("negate(10) = %d\n",negate(10));
    printf("negate(0) = %d\n",negate(0));
    printf("negate(-10) = %d\n",negate(-10));

    return EXIT_SUCCESS;
}