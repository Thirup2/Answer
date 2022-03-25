#include <stdio.h>
int main(void)
{
    int n;
    int sign;
    scanf("%d",&n);
    if(n<0){
        sign = -1;
    }else if(n==0){
        sign = 0;
    }else{
        sign = 1;
    }
    printf("sign(%d) = %d\n",n,sign);

    return 0;
}