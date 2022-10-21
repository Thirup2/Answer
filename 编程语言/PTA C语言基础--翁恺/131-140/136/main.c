#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    int count = 0;
    for (int men = 0; men <= n / 3; ++men) {
        for (int women = 0; women <= n / 2; ++women) {
            for (int kids = 0; kids <= 2 * n; kids += 2) {
                if (3 * men + 2 * women + kids / 2 == n && men + women + kids == n) {
                    printf("men = %d, women = %d, child = %d\n", men, women, kids);
                    ++count;
                }
            }
        }
    }
    if (count == 0) {
        printf("None");
    }
    return 0;
}