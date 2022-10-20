#include <stdio.h>
int main(void)
{
    int x;
    int count = 0;
    scanf("%d", &x);
    for (int fen5 = x / 5; fen5 > 0; --fen5) {
        for (int fen2 = x / 2; fen2 > 0; --fen2) {
            for (int fen1 = x; fen1 > 0; --fen1) {
                if (fen1 + fen2 * 2 + fen5 * 5 == x) {
                    printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n", fen5, fen2, fen1, (fen5 + fen2 + fen1));
                    count++;
                }
            }
        }
    }
    printf("count = %d", count);

    return 0;
}