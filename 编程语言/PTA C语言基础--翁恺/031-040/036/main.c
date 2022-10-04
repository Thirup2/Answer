#include <stdio.h>
int main(void)
{
    for (int i = 1;; i++) {
        if (i % 5 == 1 && i % 6 == 5 && i % 7 == 4 && i % 11 == 10) {
            printf("%d\n", i);
            return 0;
        }
    }
}