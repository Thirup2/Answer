#include <stdio.h>
int IsItPrime(int i);
int main(void)
{
    for (int i = 2; i <= 100; i++) {
        if (IsItPrime(i) == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
int IsItPrime(int i)
{
    for (int n = 2; n < i; n++) {
        if (i % n == 0) {
            return 0;
        }
    }
    return 1;
}