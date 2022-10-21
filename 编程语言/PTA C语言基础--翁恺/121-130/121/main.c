#include <stdio.h>
int main(void)
{
    int count;
    scanf("%d", &count);
    double sum = 0;
    double n;
    double max, min;
    for (int i = 0; i < count; ++i) {
        scanf("%lf", &n);
        if (i == 0) {
            max = n;
            min = n;
        } else {
            if (max < n) {
                max = n;
            }
            if (min > n) {
                min = n;
            }
        }
        sum += n;
    }
    printf("%.2lf", (sum - max - min) / (count - 2));

    return 0;
}