#include <stdio.h>
int sam(int m)
{//判断素数 
    int i;
    if (m < 2)	return 0;
    for (i = 2; i * i <= m; i++) {
        if (m % i == 0)	return 0;
    }
    return 1;
}
int main()
{
    int L, k, i, num;
    char n[1000], arr[10] = {0};//字符长度为 L ，K 位连续数字，长度为 L 的正整数 N字符串
    scanf("%d %d %s", &L, &k, n);//L==strlen(n)
    for (i = 0; i <= L - k; i++) {
        strncpy(arr, n + i, k);//strncpy()函数用于将指定长度的字符串复制到字符数组
        if (sam(atoi(arr))) {//atoi()把字符串转换成整型数的一个函数
            printf("%s", arr);
            return 0;
        }
    }
    printf("404");
    return 0;
}