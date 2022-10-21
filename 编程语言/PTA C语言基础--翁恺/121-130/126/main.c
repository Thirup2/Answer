#include <stdio.h>
int main(void)
{
    int hh1, hh2, mm1, mm2;
    scanf("%d:%d %d:%d", &hh1, &mm1, &hh2, &mm2);
    int hh, mm;
    hh = hh2 - hh1;
    mm = mm2 - mm1;
    if (mm < 0) {
        mm += 60;
        hh -= 1;
    }
    printf("%d %d", hh, mm);

    return 0;
}