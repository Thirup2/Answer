#include <stdio.h>
#define HMEAN(X,Y) (1/((1/(X)+1/(Y))/2))
int main()
{
    double f1,f2;
    printf("Enter two float number:");
    scanf("%lf %lf",&f1,&f2);
    printf("The %f and %f's HMEAN is %lf",f1,f2,HMEAN(f1,f2));

    return 0;
}