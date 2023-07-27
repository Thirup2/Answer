#include <stdio.h>
#define SPY 3.156e7

int main(void)
{
    int age;
    printf("please input your age: ");
    scanf("%d", &age);
    printf("you have already lived %g seconds in your age %d\n", SPY * age, age);

    return 0;
}