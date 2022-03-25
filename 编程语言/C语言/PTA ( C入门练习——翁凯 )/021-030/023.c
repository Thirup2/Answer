#include <stdio.h>
int main(void)
{
    double x,y;
    scanf("%lf",&x);
    if(x>0){
        if(x<=15){
            y=4.0*x/3.0;
        }else{
            y=2.5*x-17.5;
        }
    }
    printf("%.2lf",y);

    return 0;
}