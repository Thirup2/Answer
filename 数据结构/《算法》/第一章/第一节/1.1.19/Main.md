## 在计算机上运行以下程序:
```java
public class Fibonacci
{
    public static long F(int N)
    {
        if (N == 0)
            return 0;
        if (N == 1)
            return 1;
        return F(N - 1) + F(N - 2);
    }
    public static void main(String[] args)
    {
        for (int N = 0; N < 100; N++)
            StdOut.println(N + " " + F(N));
    }
}
```
## 计算机用这段程序在一个小时之内能够得到`F(N)`结果的最大`N`值是多少? 开发`F(N)`的一个更好的实现, 用数组保存已经计算过的值.

答: 估计不到100