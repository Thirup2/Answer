#include <stdio.h>
#include <stdlib.h>
int MaxSum(int a[], int x);
int main(void)
{
    int K;
    scanf("%d", &K);
    int n;
    if (K == 1) {
        scanf("%d", &n);
        printf("%d", n);
        return 0;
    }
    int *a = (int *) malloc(K * sizeof(int));
    if (!a) {
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < K; i++) {
        scanf("%d", &n);
        a[i] = n;
    }
    int sum;
    sum = MaxSum(a, K);
    free(a);
    printf("%d", sum);
    return 0;
}
int MaxSum(int a[], int x)
{
    int thissum = 0, maxsum = 0;
    for (int i = 0; i < x; i++) {
        thissum += a[i];
        if (thissum > maxsum) {
            maxsum = thissum;
        }
        if (thissum < 0) {
            thissum = 0;
        }
    }
    return maxsum;
}