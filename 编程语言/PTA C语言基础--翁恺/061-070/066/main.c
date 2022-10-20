#include <stdio.h>
int main(void)
{
    int hh, mm, ss, n;
    scanf("%d:%d:%d\n%d", &hh, &mm, &ss, &n);
    ss += n;
    while (ss >= 60) {
        ++mm;
        ss -= 60;
    }
    while (mm >= 60) {
        ++hh;
        mm -= 60;
    }
    while (hh >= 24) {
        hh -= 24;
    }
    printf("%02d:%02d:%02d", hh, mm, ss);

    return 0;
}