## 下面这段代码有什么问题？
```java
int[] a;
for (int i = 0; i < 10; i++)
    a[i] = i * i;
```
答：没有用`new`为`a[]`分配内存