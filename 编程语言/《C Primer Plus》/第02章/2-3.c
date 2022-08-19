#include <stdio.h>
#define Year 365
int main(void)
{
    int age;
    printf("Please enter your age:\n");
    scanf("%d",&age);
    printf("%d ages = %d days\n",age,Year*age);

    return 0;
}