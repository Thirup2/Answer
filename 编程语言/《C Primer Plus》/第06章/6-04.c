#include <stdio.h>
int main(void)
{
    char ch = 'A';
    char targ;
    printf("请输入你想要打印到的字符(大写字母): ");
    scanf("%c", &targ);
    for (int i = 0; ch <= targ; i++) {
        for (int j = 0; j <= i && ch <= targ; j++) {
            printf("%c ", ch++);
        }
        printf("\n");
    }

    return 0;
}