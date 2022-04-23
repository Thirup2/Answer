#include <stdio.h>
int main(void)
{
    float n;
    printf("Enter a floating-point value: \n");
    scanf("%f",&n);
    printf("fixed-point notation: %f\n",n);
    printf("exponential notation: %e\n",n);
    printf("p notation: %.2a\n",n);

    return 0;
}