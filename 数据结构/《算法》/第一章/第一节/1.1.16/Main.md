## 给出`exR1(6)`的返回值
```java
public static String exR1(int n)
{
    if (n <= 0)
        return "";
    return exR1(n - 3) + n + exR1(n - 2) + n;
}
```
返回值:
```
311361142246
```