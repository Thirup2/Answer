#include <stdio.h>
unsigned long Fibonacci(unsigned n);
int main(void)
{
    unsigned n;
    printf("请输入斐波那契数的项数:");
    while(scanf("%u",&n)==1){
        printf("第%u项的斐波那契数是:%lu\n",n,Fibonacci(n));
        printf("请输入斐波那契数的项数:");
    }
    printf("Done\n");

    return 0;
}
unsigned long Fibonacci(unsigned n)
{
    unsigned f1=1;
    unsigned f2=1;
    unsigned temp=0;
    if(n==1||n==2){
        return 1;
    }else{
        for(int i=3;i<=n;i++){
            temp=f1+f2;
            f1=f2;
            f2=temp;
        }
        return temp;
    }
}