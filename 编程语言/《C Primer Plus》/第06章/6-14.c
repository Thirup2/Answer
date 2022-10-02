#include <stdio.h>
int main(void)
{
    double arr[8];
    for (int i = 0; i < 8; i++) {
        scanf("%lf", &arr[i]);
    }
    double copy[8];
    copy[0] = arr[0];
    for (int i = 1; i < 8; i++) {
        copy[i] = copy[i - 1] + arr[i];
    }
    for (int i = 0; i < 8; i++) {
        printf("%-10g", arr[i]);
    }
    printf("\n");
    for (int i = 0; i < 8; i++) {
        printf("%-10g", copy[i]);
    }
    printf("\n");
    return 0;
}