#include <stdio.h>
#include <stdbool.h>
#define MAX 100
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
    for (int i = 0; i < MAX; ++i) {
        if (eratosthenes[i] == true) {
            printf("%d ", i+2);
        }
    }
    printf("\n");

    return 0;
}