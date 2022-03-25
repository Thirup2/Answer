#include <stdio.h>
int main(void)
{
    int speed;
    scanf("%d",&speed);
    if(speed>=0&&speed<=500){
        if(speed<=60){
            printf("Speed: %d - OK",speed);
        }else{
            printf("Speed: %d - Speeding",speed);
        }
    }

    return 0;
}