## 请看以下递归函数:
```java
public static int mystery(int a, int b)
{
    if (b == 0)
        return 0;
    if (b % 2 == 0)
        return mystery(a + a, b / 2);
    return mystery(a + a, b / 2) + a;
}
```
## (1) `mystery(2, 25)`和`mystery(3, 11)`的返回值是多少?
## (2) 给定正整数`a`和`b`, `mystery(a, b)`计算的结果是什么?
## (3) 将代码中的`+`替换为`*`并将`return 0`改为`return 1`, 然后回答上面两个问题.

### (1)
答:
```
50
33
```

### (2)
答:
```
a * b
```

### (3)
- 问题1
答:
    ```
    33554432
    177147
    ```

- 问题2
答:
    ```
    a^b
    ```