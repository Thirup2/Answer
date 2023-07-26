#include <stdio.h>
#include <stdarg.h>

int array_offset(int arrayinfo[], ...);

int main(void)
{
    int arrayinfo[7] = {
        3,
        4, 6,
        1, 5,
        -3, 3
    };
    int undernum[3] = {
        6, 5, 3
    };
    int loc;
    loc = array_offset(arrayinfo, undernum[0], undernum[1], undernum[2]);

    if (loc == -1) {
        printf("维数错误！\n");
        return -1;
    } else if (loc == -2) {
        printf("low 大于 high！\n");
        return -2;
    } else if (loc == -3) {
        printf("下标错误！\n");
        return -3;
    } else {
        printf("偏移量为：%d\n", loc);
        return 0;
    }
}

int array_offset(int arrayinfo[], ...)
{
    if (arrayinfo[0] < 1 || arrayinfo[0]>10) {
        return -1;              // 维数错误
    }
    for (int i = 1; i <= 2 * arrayinfo[0]; i += 2) {
        if (arrayinfo[i] > arrayinfo[i + 1]) {
            return -2;          // low大于high
        }
    }
    va_list list;
    int loc = 0;
    va_start(list, arrayinfo);
    int now;
    for (int i = 1; i <= arrayinfo[0]; i++) {
        now = va_arg(list, int);
        if (now < arrayinfo[2 * i - 1] || now > arrayinfo[2 * i]) {
            return -3;              // 下标错误
        }
        if (i == 1) {
            loc = now - arrayinfo[2 * i - 1];
        } else if (i == 2) {
            loc += (now - arrayinfo[2 * i - 1]) * (arrayinfo[2 * (i - 1)] - arrayinfo[2 * (i - 1) - 1] + 1);
        } else {
            loc += ((now - arrayinfo[2 * i - 1]) * (arrayinfo[2 * (i - 1)] - arrayinfo[2 * (i - 1) - 1] + 1)) * (arrayinfo[2 * (i - 2)] - arrayinfo[2 * (i - 2) - 1] + 1);
        }
    }
    va_end(list);
    return loc;
}