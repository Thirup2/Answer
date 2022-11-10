#include <stdio.h>
#include <string.h>
#define SIZE 20
int substr(char dst[], char src[], int start, int len);
int main(void)
{
    char src[] = "this is a test string, and there are some litters.";
    char dst[SIZE];
    int start;
    scanf("%d", &start);
    int r = substr(dst, src, start, SIZE - 1);
    if (r == -1) {
        printf("初始位置或复制长度错误！\n");
        return -1;
    } else {
        puts(dst);
    }
    return 0;
}
int substr(char dst[], char src[], int start, int len)
{
    if (start >= strlen(src) || start < 0 || len < 0) {
        return -1;
    }
    int i = 0;
    int j = start;
    while (i < len) {
        if (src[j] == '\0') {
            dst[i] = '\0';
            return i;
        }
        dst[i] = src[j];
        i++;
        j++;
    }
    dst[SIZE - 1] = '\0';
    return SIZE;
}