#include <stdio.h>
int main(void)
{
    int A, B;
    scanf("%d %d", &A, &B);
    printf("%d/", A);
    if (B > 0) {
        printf("%d=%.2lf", B, (double) A / B);
    } else if (B == 0) {
        printf("%d=Error", B);
    } else {
        printf("(%d)=%.2lf", B, (double) A / B);
    }
    return 0;
}