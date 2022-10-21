#include <stdio.h>
void simple(int *son, int *mother);
int main(void)
{
    int son, mother;
    scanf("%d/%d", &son, &mother);
    simple(&son, &mother);
    printf("%d/%d", son, mother);
    return 0;
}
void simple(int *son, int *mother)
{
    int min = (*son < *mother) ? *son : *mother;
    for (int i = min; i >= 1; --i) {
        if (*son % i == 0 && *mother % i == 0) {
            *son /= i;
            *mother /= i;
        }
    }
}