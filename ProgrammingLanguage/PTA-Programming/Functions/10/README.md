# 阶乘计算升级版
本题要求实现一个打印非负整数阶乘的函数。

### 函数接口定义：
```c
void Print_Factorial ( const int N );
```
其中`N`是用户传入的参数，其值不超过1000。如果`N`是非负整数，则该函数必须在一行中打印出`N`!的值，否则打印“Invalid input”。

### 裁判测试程序样例：
```c
#include <stdio.h>

void Print_Factorial ( const int N );

int main()
{
    int N;
    
    scanf("%d", &N);
    Print_Factorial(N);
    return 0;
}

/* 你的代码将被嵌在这里 */
```
### 输入样例：
```
15
```
### 输出样例：
```
1307674368000
```