#include <stdio.h>
int main(void)
{
    int num1, num2;
    char ch;
    scanf("%d %c %d", &num1, &ch, &num2);
    switch (ch) {
        case '+':
            printf("%d", num1 + num2);
            break;
        case '-':
            printf("%d", num1 - num2);
            break;
        case '*':
            printf("%d", num1 * num2);
            break;
        case '/':
            printf("%d", num1 / num2);
            break;
        case '%':
            printf("%d", num1 % num2);
            break;
        default:
            printf("ERROR");
            break;
    }
    return 0;
}