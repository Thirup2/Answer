#include <stdio.h>
#include <math.h>
int main(void)
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a + b > c && a + c > b && b + c > a) {
        double s;
        double area;
        double perimeter;
        perimeter = a + b + c;
        s = perimeter / 2.0;
        area = sqrt(s * (s - a) * (s - b) * (s - c));
        printf("area = %.2lf; perimeter = %.2lf", area, perimeter);
    } else {
        printf("These sides do not correspond to a valid triangle");
    }
    return 0;
}