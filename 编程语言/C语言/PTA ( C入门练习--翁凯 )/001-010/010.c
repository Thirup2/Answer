#include <stdio.h>
int main(void)
{
    int a,b;
    
    scanf("%d %d",&a,&b);

    while(a>=0&&a<=100&&b>=0&&b<=100){
        printf("%d + %d = %d\n",a,b,a+b);
        printf("%d - %d = %d\n",a,b,a-b);
        printf("%d * %d = %d\n",a,b,a*b);
        if(a%b==0){
            printf("%d / %d = %d\n",a,b,a/b);
        }else{
            printf("%d / %d = %.2f\n",a,b,((float)a/b));
        }
        break;
    }

    return 0;
}