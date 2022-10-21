#include <stdio.h>
int main(void)
{
    int time1, time2;
    scanf("%d %d", &time1, &time2);
    int hh1, mm1, hh2, mm2;
    hh1 = time1 / 100;
    mm1 = time1 % 100;
    hh2 = time2 / 100;
    mm2 = time2 % 100;
    int hh, mm;
    hh = hh2 - hh1;
    mm = mm2 - mm1;
    if (mm < 0) {
        mm += 60;
        hh -= 1;
    }
    printf("%02d:%02d", hh, mm);

    return 0;
}