#include <stdio.h>
int main(void)
{
    int A_count, B_count;
    scanf("%d %d", &A_count, &B_count);
    int N;
    scanf("%d", &N);
    int count_a = 0, count_b = 0;
    int A_loud, A_act, B_loud, B_act;
    for (int i = 1; i <= N; ++i) {
        scanf("%d %d %d %d", &A_loud, &A_act, &B_loud, &B_act);
        if (A_act == A_loud + B_loud && B_act != A_act) {
            ++count_a;
        }
        if (B_act == A_loud + B_loud && A_act != B_act) {
            ++count_b;
        }
        if (count_a > A_count || count_b > B_count) {
            break;
        }
    }
    if (count_a > A_count) {
        printf("A\n");
        printf("%d", count_b);
    }
    if (count_b > B_count) {
        printf("B\n");
        printf("%d", count_a);
    }
    return 0;
}