#include <stdio.h>
int main(void)
{
    double eps;
    scanf("%lf", &eps);
    double son = 1.0;
    double mother = 1.0;
    int count = 0;
    double sum = 1.0;
    for (count = 1; (son / mother) > eps; ++count) {
        mother += 3;
        if (count % 2 == 0) {
            sum += son / mother;
        } else {
            sum -= son / mother;
        }
    }
    printf("sum = %.6lf", sum);

    return 0;
}