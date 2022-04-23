#include <stdio.h>
#define IC "India, China"
#define BR "Brazil, Russia"
void br(void);
void ic(void);
int main(void)
{
    br();
    printf(", ");
    ic();
    ic();
    br();
    printf("\n");

    return 0;
}
void br(void)
{
    printf("%s",BR);
}
void ic(void)
{
    printf("%s\n",IC);
}