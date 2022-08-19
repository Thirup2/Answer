#include <stdio.h>
int main(void)
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int max, mid, min;
    if (a > b) {
        if (a > c) {
            max = a;
            if (b > c) {
                mid = b;
                min = c;
            } else {
                mid = c;
                min = b;
            }
        } else {
            max = c;
            mid = a;
            min = b;
        }
    } else {
        if (a < c) {
            min = a;
            if (b < c) {
                mid = b;
                max = c;
            } else {
                mid = c;
                max = b;
            }
        } else {
            max = b;
            mid = a;
            min = c;
        }
    }
    printf("%d->%d->%d", min, mid, max);

    return 0;
}