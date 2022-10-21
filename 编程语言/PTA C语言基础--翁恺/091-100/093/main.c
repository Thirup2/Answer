#include<stdio.h>
int po(int a, int b)
{
    int c = 1;
    while (b > 0) {
        c *= a;
        b--;
    }
    return c;//pow函数是double类型运行慢，自己写n=7才不会运行超时。
}			 //I don't happy about that either,but whatever.
int main()
{
    int n;
    scanf("%d", &n);
    int x = po(10, n);//10的n次方
    int y = po(10, n - 1);
    for (int i = y; i < x; i++) {//限定i在n位数范围，n=3 : i=100;i<1000;i++
        int a, sum = 0;
        int j = i;
        while (j > 0) {
            a = j % 10;//取个位数 j=153:a=3
            j /= 10;//个位数去掉 j=15
            sum += po(a, n);//位数的n次方和
        }
        if (sum == i) {
            printf("%d\n", i);
        }
    }
    //printf("s = %d",sum);
    return 0;
}
