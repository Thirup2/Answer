#include <stdio.h>
int main(void)
{
    int F;
    int C;
    
    scanf("%d",&F);
    
    C = 5 * ( F - 32 ) / 9;
    
    printf("Celsius = %d",C);
    
    return 0;
}