## 找出以下递归函数的问题:
```java
public static String exR2(int n)
{
    String s = exR2(n - 3) + n + exR2(n - 2) + n;
    if (n <= 0)
        return "";
    return s;
}
```
答: 由于递归语句在前, 所以该语句将会一直递归, 不会遇到返回语句.