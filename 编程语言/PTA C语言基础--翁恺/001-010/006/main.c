#include <stdio.h>
int main(void)
{
    int cm;
    int feet;
    int inch;
    
    scanf("%d",&cm);
    
    inch = (int) (cm / 30.48 * 12);
    feet = inch / 12;
    inch = inch % 12;
    printf("%d %d", feet, inch);
    
    return 0;
}