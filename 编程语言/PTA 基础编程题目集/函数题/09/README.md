# 统计个位数字
本题要求实现一个函数，可统计任一整数中某个位数出现的次数。例如-21252中，2出现了3次，则该函数应该返回3。

### 函数接口定义：
```c
int Count_Digit ( const int N, const int D );
```
其中`N`和`D`都是用户传入的参数。`N`的值不超过`int`的范围；`D`是[0, 9]区间内的个位数。函数须返回`N`中`D`出现的次数。

### 裁判测试程序样例：
```c
#include <stdio.h>

int Count_Digit ( const int N, const int D );

int main()
{
    int N, D;
    
    scanf("%d %d", &N, &D);
    printf("%d\n", Count_Digit(N, D));
    return 0;
}

/* 你的代码将被嵌在这里 */
```
### 输入样例：
```
-21252 2
```
### 输出样例：
```
3
```