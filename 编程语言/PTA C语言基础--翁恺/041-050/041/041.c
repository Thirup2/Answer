#include <stdio.h>
int main(void)
{
    int N;
    int sum = 0;
    int sum_s = 1;
    scanf("%d", &N);
    for (int i = N; i > 0; i--) {
        sum_s = 1;
        int j = i;
        while (j > 1) {
            sum_s *= j;
            j--;
        }
        sum += sum_s;
    }
    printf("%d", sum);
    return 0;
}