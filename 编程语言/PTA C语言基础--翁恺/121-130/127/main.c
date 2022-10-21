#include <stdio.h>
int sum_of_digits(int num);
int main(void)
{
    int num;
    scanf("%d", &num);
    printf("%d", sum_of_digits(num));
    return 0;
}
int sum_of_digits(int num)
{
    int result = 0;
    while (num != 0) {
        result += num % 10;
        num /= 10;
    }
    return result;
}