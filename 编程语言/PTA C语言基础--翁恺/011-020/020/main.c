#include <stdio.h>
int main(void)
{
    int num1, num2;
    char sym;
    scanf("%d", &num1);
    while (scanf("%c", &sym) == 1 && sym != '=') {
        scanf("%d", &num2);
        switch (sym) {
            case '+':
                num1 += num2;
                break;
            case '-':
                num1 -= num2;
                break;
            case '*':
                num1 *= num2;
                break;
            case '/':
                if (num2 == 0) {
                    printf("ERROR\n");
                    return 0;
                }
                num1 /= num2;
                break;
            default:
                printf("ERROR\n");
                return 0;
        }
    }
    printf("%d\n", num1);

    return 0;
}