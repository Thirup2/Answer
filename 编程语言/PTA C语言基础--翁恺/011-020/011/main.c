#include <stdio.h>
#define math 87
#define english 72
#define com 93
int main(void)
{
    int average;
    
    average = (math+english+com)/3;

    printf("math = %d, eng = %d, comp = %d, average = %d\n",math,english,com,average);

    return 0;
}