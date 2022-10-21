#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    int height;
    int max = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &height);
        if (height > max) {
            max = height;
        }
    }
    printf("%d", max);
    return 0;
}