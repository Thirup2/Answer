#include <stdio.h>
int pyfh(int);
int lifh(int);
int main(void)
{
    int mini,maxi;
    printf("请输入你想要求平方和立方的整数范围:");
    scanf("%d %d",&mini,&maxi);
    printf("%-10s%-10s%-10s\n","x","x^2","x^3");
    for(;mini<=maxi;mini++){
        printf("%-10d%-10d%-10d\n",mini,pyfh(mini),lifh(mini));
    }

    return 0;
}
int pyfh(int i)
{
    return i*i;
}
int lifh(int i)
{
    return i*i*i;
}