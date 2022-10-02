#include <stdio.h>
int main(void)
{
    int speed;
    scanf("%d", &speed);
    printf("Speed: %d - %s\n", speed, speed > 60 ? "Speeding" : "OK");
    return 0;
}