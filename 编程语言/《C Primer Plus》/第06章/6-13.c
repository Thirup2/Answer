#include <stdio.h>
int In_pow(int x, int y);
int main(void)
{
    int square[8];
    for (int i = 0; i < 8; i++) {
        square[i] = In_pow(2, i);
    }
    int i = 0;
    do {
        printf("%d ", square[i++]);
    } while (i < 7);
    printf("%d\n", square[i]);

    return 0;
}
int In_pow(int x, int y)
{
    int result = 1;
    for (int i = 0; i < y; i++) {
        result *= x;
    }
    return result;
}