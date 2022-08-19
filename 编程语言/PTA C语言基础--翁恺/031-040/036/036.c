#include <stdio.h>
int main(void)
{
    int m = 0;
    int r = 1;
    while (r) {
        m++;
        if (m % 5 == 1) {
            if (m % 6 == 5) {
                if (m % 7 == 4) {
                    if (m % 11 == 10) {
                        r = 0;
                    }
                }
            }
        }
    }
    printf("%d", m);

    return 0;
}