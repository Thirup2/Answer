#include <stdio.h>
void Smile(void);
int main(void)
{
    Smile(); Smile(); Smile();
    printf("\n");
    Smile(); Smile();
    printf("\n");
    Smile();
    printf("\n");

    return 0;
}
void Smile(void)
{
    printf("Smile!");
}