#include <stdio.h>
#include <math.h>
int main(void)
{
    double x1, y1, x2, y2, x3, y3;
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
    double a, b, c;
    a = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    b = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
    c = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
    if (a + b > c && a + c > b && b + c > a) {
        double L, A, S;
        L = a + b + c;
        S = L / 2;
        A = sqrt(S * (S - a) * (S - b) * (S - c));
        printf("L = %.2lf, A = %.2lf", L, A);
    } else {
        printf("Impossible");
    }

    return 0;
}