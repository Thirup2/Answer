#include <stdio.h>
int main(void)
{
    int N;
    scanf("%d", &N);
    int max_a1, sum_a3 = 0;
    int a1_count = 0, a2_cnt = 0, a3_cnt = 0;
    int num;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &num);
        if (num % 3 == 0) {
            if (a1_count == 0) {
                max_a1 = num;
                a1_count++;
            } else {
                max_a1 = (num > max_a1) ? num : max_a1;
                a1_count++;
            }
        }
        if ((num - 1) % 3 == 0) {
            ++a2_cnt;
        }
        if ((num + 1) % 3 == 0) {
            sum_a3 += num;
            a3_cnt++;
        }
    }
    if (a1_count > 0) {
        printf("%d ", max_a1);
    } else {
        printf("NONE ");
    }
    if (a2_cnt > 0) {
        printf("%d ", a2_cnt);
    } else {
        printf("NONE ");
    }
    if (a3_cnt > 0) {
        printf("%.1lf", (double) sum_a3 / a3_cnt);
    } else {
        printf("NONE");
    }
    return 0;
}