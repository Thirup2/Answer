#include <stdio.h>
int Is_singlenum(int n);
int main(void)
{
    int n;
    scanf("%d", &n);
    int temp = n;
    int count = 0;
    printf("%d=", temp);
    while (temp != 1) {
        for (int i = 2; i <= temp; ++i) {
            if (temp % i == 0) {
                if (Is_singlenum(i)) {
                    if (count == 0) {
                        printf("%d", i);
                    } else {
                        printf("*%d", i);
                    }
                    temp /= i;
                    i--;
                    ++count;
                }
            }
        }
    }
    return 0;
}
int Is_singlenum(int n)
{
    int count = 0;
    for (int i = 2; i < n; ++i) {
        if (n % i == 0) {
            ++count;
        }
    }
    if (count == 0) {
        return 1;
    } else {
        return 0;
    }
}