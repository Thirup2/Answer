#include <stdio.h>
#include <stdbool.h>
#define MAX 100000
int main(void)
{
    bool eratosthenes[MAX];
    for (int i = 0; i < MAX; ++i) {
        eratosthenes[i] = true;
    }
    for (int i = 0; i < MAX; ++i) {
        if (eratosthenes[i] == false) {
            continue;
        } else {
            for (int j = i; j < MAX;) {
                ++j;
                if ((j + 2) % (i + 2) == 0) {
                    eratosthenes[j] = false;
                }
            }
        }
    }
    int count = 0;
    for (int i = 0; i < MAX; ++i) {
        if (eratosthenes[i] == true) {
            count++;
        }
        if ((i + 2) % 1000 == 0) {
            printf("%d~%d: ", i + 2 - 1000, i + 2);
            printf("%d\n", count);
            count = 0;
        }
    }

    return 0;
}