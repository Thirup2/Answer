#include <stdio.h>
#include <stdlib.h>
int main()
{
    char l[21];//因为最大数值超出long long int的范围，所以采用字符串输入；
    int a[21], b[22];//用来记录转换的值；
    int n = 0, i, j;//标记数的长度；
    scanf("%s", l);
    for (i = 0; l[i] != '\0'; i++) {
        if (l[i] != '\0') {
            a[i] = l[i] - '0';
            b[i] = a[i] * 2;
            n++; //记录输入数据的位数；
        }
    }
    for (i = n - 1; i > 0; i--) //进位；
    {
        for (j = i; j > 0; j--) {
            if (b[j] > 9) {
                b[j] -= 10;
                b[j - 1] += 1;
            }
        }
    }
    //判别；
    int a1[10] = {0,0,0,0,0,0,0,0,0,0};
    int a2[10] = {0,0,0,0,0,0,0,0,0,0};
    if (b[0] > 9)
        printf("No\n");
    else {
        for (i = 1; i < 10; i++) {
            for (j = 0; j < 10; j++) {
                if (a[j] == i)
                    a1[i]++;
                if (b[j] == i)
                    a2[i]++;
            }
        }
        for (i = 1; i < 10; i++) {
            if (a1[i] == a2[i]);
            else
                break;
        }
        if (i == 10)
            printf("Yes\n");
        else
            printf("No\n");
    }
    for (i = 0; i < n; i++)
        printf("%d", b[i]);

    return 0;
}
