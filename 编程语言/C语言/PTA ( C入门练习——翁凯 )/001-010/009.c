#include <stdio.h>
int main(void)
{
    int a,b,c,d;
    int sum;
    double average;
    scanf("%d %d %d %d",&a,&b,&c,&d);

    sum = a + b + c + d;
    average = sum / 4.0;

    printf("Sum = %d; Average = %.1lf",sum,average);

    return 0;
}