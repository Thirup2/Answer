#include <stdio.h>
#define D_W 7
int main(void)
{
    int d;

    scanf("%d",&d);
    if(d==5){
        printf("%d",7);
    }else{
        d=(d+2)%D_W;
        printf("%d",d);
    }
    return 0;
}