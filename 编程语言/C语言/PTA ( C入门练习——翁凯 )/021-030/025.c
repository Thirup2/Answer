#include <stdio.h>
int main(void)
{
    int n;
    int sum=0;
    while(scanf("%d",&n)==1&&n>0){
        if(n%2==1){
            sum+=n;
        }
    }
    printf("%d",sum);

    return 0;
}