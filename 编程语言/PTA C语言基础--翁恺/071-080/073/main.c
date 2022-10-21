#include <stdio.h>
int main(void)
{
    int num[3];
    for (int i = 0; i < 3; i++) {
        scanf("%d", &num[i]);
    }
    int temp;
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (num[j] < num[i]) {
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }
    printf("%d", num[0]);
    for (int i = 1; i < 3; i++) {
        printf("->%d", num[i]);
    }

    return 0;
}