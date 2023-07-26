# 简单求和
本题要求实现一个函数，求给定的`N`个整数的和。

### 函数接口定义：
```c
int Sum ( int List[], int N );
```
其中给定整数存放在数组`List[]`中，正整数`N`是数组元素个数。该函数须返回`N`个`List[]`元素的和。

### 裁判测试程序样例：
```c
#include <stdio.h>

#define MAXN 10

int Sum ( int List[], int N );

int main ()
{
    int List[MAXN], N, i;

    scanf("%d", &N);
    for ( i=0; i<N; i++ )
        scanf("%d", &List[i]);
    printf("%d\n", Sum(List, N));

    return 0;
}

/* 你的代码将被嵌在这里 */
```
输入样例：
```
3
12 34 -5
```
输出样例：
```
41
```