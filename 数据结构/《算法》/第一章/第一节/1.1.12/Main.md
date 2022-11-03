## 以下代码段会打印出什么结果?
```java
int[] a = new int[10];
for (int i = 0; i < 10; i++)
    a[i] = 9 - i;
for (int i = 0; i < 10; i++)
    a[i] = a[a[i]];
for (int i = 0; i < 10; i++)
    System.out.println(a[i]);
```
输出:
```
0
1
2
3
4
4
3
2
1
0
```