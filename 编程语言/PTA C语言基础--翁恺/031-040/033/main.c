#include <stdio.h>
int main(void)
{
    int M;
    int N;
    int count = 0;
    int sum = 0;
    scanf("%d %d", &M, &N);
    int i = M;
    int j = N;
    int r = 1;
    while (i <= j) {
        if (i == 0) {
            i++;
            continue;
        }
        if (i == 1) {
            i++;
            continue;
        }
        for (int n = 2; n < i; n++) {
            if (i % n == 0) {
                r = 0;
            }
        }
        if (r) {
            count++;
            sum += i;
        } else {
            r = 1;
        }
        i++;
    }
    printf("%d %d", count, sum);

    return 0;
}