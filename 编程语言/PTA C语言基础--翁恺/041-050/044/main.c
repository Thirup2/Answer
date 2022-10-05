#include <stdio.h>
int remax(int N);
int remin(int N);
int main(void)
{
    int N;
    scanf("%d", &N);
    int i = 1;
    if (N == 495) {
        printf("%d: %d - %d = %d\n", i, 954, 459, 495);
        return 0;
    }
    while (N != 495) {
        printf("%d: ", i++);
        printf("%d - %d = %d\n", remax(N), remin(N), remax(N) - remin(N));
        N = remax(N) - remin(N);
    }

    return 0;
}
int remax(int N)
{
    int a, b, c;
    int max, mid, min;
    a = N / 100;
    c = N % 10;
    b = (N % 100) / 10;
    if (a > b) {
        if (a > c) {
            max = a;
            if (b > c) {
                mid = b;
                min = c;
            } else {
                min = b;
                mid = c;
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
int remin(int N)
{
    int a, b, c;
    int max, mid, min;
    a = N / 100;
    c = N % 10;
    b = (N % 100) / 10;
    if (a > b) {
        if (a > c) {
            max = a;
            if (b > c) {
                mid = b;
                min = c;
            } else {
                min = b;
                mid = c;
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