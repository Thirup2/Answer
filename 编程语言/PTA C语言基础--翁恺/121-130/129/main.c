#include <stdio.h>
int main(void)
{
    int N;
    scanf("%d", &N);
    char sex;
    double height;
    for (int i = 1; i <= N; ++i) {
        while (getchar() != '\n') {
            continue;
        }
        scanf("%c %lf", &sex, &height);
        if (sex == 'M') {
            printf("%.2lf\n", height / 1.09);
        }
        if (sex == 'F') {
            printf("%.2lf\n", height * 1.09);
        }
    }
    return 0;
}