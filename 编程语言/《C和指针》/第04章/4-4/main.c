#include <stdio.h>
void copy_n(char dst[], char src[], int n);
int main(void)
{
    char dst[20] = "this is a test.";
    char src[20] = "some";
    int n;
    scanf("%d", &n);
    copy_n(dst, src, n);
    printf("%s\n", dst);

    return 0;
}
void copy_n(char dst[], char src[], int n)
{
    for (int i = 0; i < n; i++) {
        if (src[i] != '\0') {
            dst[i] = src[i];
        } else {
            for (int j = i; j < n; j++) {
                dst[j] = '\0';
            }
            i = n - 1;
        }
    }
}