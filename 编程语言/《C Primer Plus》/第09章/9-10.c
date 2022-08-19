#include <stdio.h>
void to_base_n(unsigned long n,int m);
int main(void)
{
    unsigned long number;
    int p;
    printf("请输入一个正整数以及想要使用的进制数(2<=进制数<=10):\n");
    while (scanf("%lu %d", &number,&p) == 2&&p>=2&&p<=10)
    {
        printf("Binary equivalent: ");
        to_base_n(number,p);
        putchar('\n');
        printf("请输入一个正整数以及想要使用的进制数(2<=进制数<=10):\n");
    }
    printf("Done.\n");
    
    return 0;
}

void to_base_n(unsigned long n,int m)
{
    int r;
    
    r = n % m;
    if (n >= m)
        to_base_n(n / m,m);
    printf("%d",r);
    
    return;
}