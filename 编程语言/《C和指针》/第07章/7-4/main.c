#include <stdio.h>
#include <stdarg.h>
int max_list(int n_nums, ...);
int main(void)
{
    printf("%d\n", max_list(3, 1, 2, 3, -1));
    printf("%d\n", max_list(5, 9, 5, 1, 4, 3, -1));
    printf("%d\n", max_list(10, 5, 8, 20, 3, 4, 67, 4, 3, 9, 10, -1));

    return 0;
}
int max_list(int n_nums, ...)
{
    va_list list;
    va_start(list, n_nums);
    int max = va_arg(list, int);
    int now;
    while ((now = va_arg(list, int)) >= 0) {
        if (now > max) {
            max = now;
        }
    }
    va_end(list);
    return max;
}