/* 字符串驱动程序源文件driver.c, 和String.c一起编译 */

/* 包含头文件 */
#include "String.h"

int main(void)
{
    int n = Index_KMP("This is a file.", "fi", 1);
    printf("%d", n);

    return 0;
}