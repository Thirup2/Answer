#include <stdio.h>
int main(void)
{
    int n;
    int sum = 0;
    int count = 0;
    while (scanf("%d", &n) == 1 && n >= 0) {
        sum += n;
        count++;
    }
    if (count == 0) {
        printf("None");
    } else {
        printf("%.2lf\n", (double) sum / count);
    }
    return 0;
}