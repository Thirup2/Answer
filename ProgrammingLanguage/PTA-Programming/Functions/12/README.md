# 判断奇偶性
本题要求实现判断给定整数奇偶性的函数。

### 函数接口定义：
```c
int even( int n );
```
其中`n`是用户传入的整型参数。当`n`为偶数时，函数返回1；`n`为奇数时返回0。注意：0是偶数。

### 裁判测试程序样例：
```c
#include <stdio.h>

int even( int n );

int main()
{    
    int n;

    scanf("%d", &n);
    if (even(n))
        printf("%d is even.\n", n);
    else
        printf("%d is odd.\n", n);
    
    return 0;
}

/* 你的代码将被嵌在这里 */
```
### 输入样例1：
```
-6
```
### 输出样例1：
```
-6 is even.
```
### 输入样例2：
```
5
```
### 输出样例2：
```
5 is odd.
```