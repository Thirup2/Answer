#include <stdio.h>
int main(void)
{
    int m,n;
    int min,max;
    int max_m,min_m;
    scanf("%d %d",&m,&n);
    if(m>=1&&m<=1000&&n>=1&&n<=1000){
        if(m<n){
            min=m;
            max=n;
        }else{
            min=n;
            max=m;
        }
        for(int i=1;i<=min;i++){
            if(m%i==0&&n%i==0){
                max_m=i;
            }
        }
        for(int i=m*n;i>=max;i--){
            if(i%m==0&&i%n==0){
                min_m=i;
            }
        }
        printf("%d %d",max_m,min_m);
    }

    return 0;
}