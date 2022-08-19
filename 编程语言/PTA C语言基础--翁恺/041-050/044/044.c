#include <stdio.h>
int Max_re(int n);
int Min_re(int n);
int main(void)
{
    int n, n_old = -1;
    scanf("%d", &n);
    int max_re;
    int min_re;
    int i = 0;
    if (n == 495) {
        printf("1: 954 - 459 = 495\n");
        return 0;
    }
    while (n != n_old) {
        if (i > 0) {
            printf("%d: %d - %d = %d\n", i, max_re, min_re, n);
        }
        i++;
        max_re = Max_re(n);
        min_re = Min_re(n);
        n_old = n;
        n = max_re - min_re;
    }

    return 0;
}
int Max_re(int n)
{
    int a, b, c;
    int max, mid, min;
    c = n % 10;
    n = n / 10;
    b = n % 10;
    n = n / 10;
    a = n % 10;
    n = n / 10;
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
    return max * 100 + mid * 10 + min;
}
int Min_re(int n)
{
    int a, b, c;
    int max, mid, min;
    c = n % 10;
    n = n / 10;
    b = n % 10;
    n = n / 10;
    a = n % 10;
    n = n / 10;
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
    return min * 100 + mid * 10 + max;
}