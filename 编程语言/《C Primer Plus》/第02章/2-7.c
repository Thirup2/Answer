#include <stdio.h>

void sm(void);

int main(void)
{
    for (int i = 3; i > 0; i--) {           // 或者使用如下代码：
        for (int j = 0; j < i; j++) {       // sm();sm();sm();printf("\n");
            sm();                           // sm();sm();printf("\n");
        }                                   // sm();printf("\n");
        printf("\n");
    }

    return 0;
}

void sm(void)
{
    printf("Smile!");
}