#include <stdio.h>
int main(void)
{
    int year;
    scanf("%d", &year);
    if (year <= 2000 || year > 2100) {
        printf("Invalid year!");
        return 0;
    }
    int count = 0;
    for (int i = 2001; i <= year; ++i) {
        if (i % 4 == 0) {
            if (i % 100 != 0) {
                printf("%d\n", i);
                ++count;
            }
            if (i % 400 == 0) {
                printf("%d\n", i);
                ++count;
            }
        }
    }
    if (count == 0) {
        printf("None");
    }

    return 0;
}