#include <stdio.h>
#define MAX 1000000000LL
int main(void)
{
    long long n;
    int num;
    int sum;
    scanf("%lld",&n);
    if(n==MAX){
        num=10;
        sum=1;
    }else if(n>=100000000LL&&n<MAX){
        num=9;
        sum=n/100000000LL+(n%100000000LL)/10000000LL+(n%10000000LL)/1000000LL+
            (n%1000000LL)/100000LL+(n%100000LL)/10000LL+(n%10000LL)/1000LL+
            (n%1000LL)/100LL+(n%100LL)/10LL+n%10LL;
    }else if(n>=10000000LL){
        num=8;
        sum=(n%100000000LL)/10000000LL+(n%10000000LL)/1000000LL+(n%1000000LL)/100000LL
            +(n%100000LL)/10000LL+(n%10000LL)/1000LL+(n%1000LL)/100LL+(n%100LL)/10LL+n%10LL;
    }else if(n>1000000LL){
        num=7;
        sum=(n%10000000LL)/1000000LL+(n%1000000LL)/100000LL+(n%100000LL)/10000LL+
            (n%10000LL)/1000LL+(n%1000LL)/100LL+(n%100LL)/10LL+n%10LL;
    }else if(n>100000LL){
        num=6;
        sum=(n%1000000LL)/100000LL+(n%100000LL)/10000LL+
            (n%10000LL)/1000LL+(n%1000LL)/100LL+(n%100LL)/10LL+n%10LL;
    }else if(n>10000LL){
        num=5;
        sum=(n%100000LL)/10000LL+(n%10000LL)/1000LL+(n%1000LL)/100LL+(n%100LL)/10LL+n%10LL;
    }else if(n>1000LL){
        num=4;
        sum=(n%10000LL)/1000LL+(n%1000LL)/100LL+(n%100LL)/10LL+n%10LL;
    }else if(n>100LL){
        num=3;
        sum=(n%1000LL)/100LL+(n%100LL)/10LL+n%10LL;
    }else if(n>10LL){
        num=2;
        sum=(n%100LL)/10LL+n%10LL;
    }else{
        num=1;
        sum=n%10LL;
    }
    printf("%d %d",num,sum);
    return 0;
}