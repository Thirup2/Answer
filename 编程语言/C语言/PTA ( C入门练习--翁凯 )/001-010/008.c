#include <stdio.h>
int main(void)
{
    int H;
    double S;

    scanf("%d",&H);
    while(H>100&&H<=300){
        S = (H-100.0)*0.9*2;
        printf("%.1lf",S);
        break;
    }

    return 0;
}