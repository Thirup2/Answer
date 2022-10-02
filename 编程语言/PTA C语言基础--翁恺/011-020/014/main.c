#include <stdio.h>
int main(void)
{
    int time1, time2;
    scanf("%d %d", &time1, &time2);
    int hours = time1 / 100;
    int min = time1 % 100;
    min = min + time2;
    if (min < 0) {
        hours -= ((-min) + 60) / 60;
    } else {
        hours += min / 60;
    }
    min = ((min % 60) + 60) % 60;
    hours = (hours + 24) % 24;
    printf("%01d%02d\n", hours, min);

    return 0;
}