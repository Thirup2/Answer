#include <stdio.h>
int main(void)
{
    long long num;
    printf("请输入一个正整数:");
    while(scanf("%lld",&num)==1&&num<=0){
        printf("请在正整数范围内查找,请重新输入:");
    }
    if(num==1){
        printf("该数即不是素数,也不是合数\n");
    }else if(num==2){
        printf("2是一个素数\n");
    }else{
        int ran=1;
        for(int i=2;i<num;i++){
            if(num%i==0){
                printf("%lld能被%d整除\n",num,i);
                ran=0;
            }
        }
        if(ran){
            printf("%lld是一个素数\n",num);
        }
    }

    return 0;
}