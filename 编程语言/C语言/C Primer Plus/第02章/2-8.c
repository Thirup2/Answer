#include <stdio.h>
#define One "one"
#define Two "two"
#define Three "three"
void one_three(void);
void two(void);
int main(void)
{
    printf("starting now:\n");
    one_three();
    printf("done!\n");

    return 0;
}
void one_three(void)
{
    printf("%s\n",One);
    two();
    printf("%s\n",Three);
}
void two(void)
{
    printf("%s\n",Two);
}