#include <stdio.h>
#include <string.h>
int main()
{
    int i, n;
    char a[15];
    scanf("%s", &a);
    char b[9] = {'\n','S','B','Q','W','S','B','Q','Y'};
    if (a[0] == '0') {
        printf("a\n"); return 0;
    }
    n = strlen(a);
    for (i = 0; i < n; i++) {
        if (a[i] == '0') {
            if (i == n - 4) printf("W");
            if (i < n - 1 && a[i + 1] == '0' || i == n - 1)continue;
            else printf("a");
        } else  printf("%c%c", a[i] + 'a' - '0', b[n - i - 1]);
    }
    return 0;
}