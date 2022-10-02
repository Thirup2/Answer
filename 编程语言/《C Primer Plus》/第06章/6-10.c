#include <stdio.h>
int work(int a, int b);
int main(void)
{
    int a, b;
    printf("Enter lower and upper integer limits: ");
    while (scanf("%d %d", &a, &b) == 2 && a < b) {
        printf("The sums of the squares from %d to %d is %d\n", a * a, b * b, work(a, b));
        printf("Enter next set of limits: ");
    }
    printf("Done\n");

    return 0;
}
int work(int a, int b)
{
    int sum = a * a;
    for (int i = a + 1; i <= b; i++) {
        sum += i * i;
    }
    return sum;
}