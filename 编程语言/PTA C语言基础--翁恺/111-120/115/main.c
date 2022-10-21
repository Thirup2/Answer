#include <stdio.h>
int main(void)
{
    int m;
    scanf("%d", &m);
    int count;
    int prin_cnt = 0;
    for (int i = m - 1; i > 1; --i) {
        count = 0;
        for (int j = 2; j < i; ++j) {
            if (i % j == 0) {
                ++count;
            }
        }
        if (count == 0) {
            printf("%6d", i);
            prin_cnt++;
        }
        if (prin_cnt == 10) {
            break;
        }
    }
    return 0;
}