#include <stdio.h>
int main(void)
{
    int m;
    scanf("%d", &m);
    int count;
    for (int i = m + 1; 1; ++i) {
        count = 0;
        for (int j = 2; j < i; ++j) {
            if (i % j == 0) {
                count++;
            }
        }
        if (count == 0) {
            printf("%d", i);
            return 0;
        }
    }
}