#include <stdio.h>
void swap(int *one, int *two);
int main(void)
{
    int thr[3];
    for (int i = 0; i < 3; i++) {
        scanf("%d", &thr[i]);
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 2; j > i; j--) {
            if (thr[j] < thr[j - 1]) {
                swap(&thr[j], &thr[j - 1]);
            }
        }
    }
    printf("%d->%d->%d\n", thr[0], thr[1], thr[2]);

    return 0;
}
void swap(int *one, int *two)
{
    int temp;
    temp = *one;
    *one = *two;
    *two = temp;
}