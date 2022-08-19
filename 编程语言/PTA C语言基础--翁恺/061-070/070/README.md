# 输出三角形面积和周长
本题要求编写程序，根据输入的三角形的三条边a、b、c，计算并输出面积和周长。注意：在一个三角形中， 任意两边之和大于第三边。三角形面积计算公式：area=$\sqrt{s(s−a)(s−b)(s−c)}$，其中s=(a+b+c)/2。

### 输入格式：
输入为3个正整数，分别代表三角形的3条边a、b、c。

### 输出格式：
如果输入的边能构成一个三角形，则在一行内，按照
```
area = 面积; perimeter = 周长
```
的格式输出，保留两位小数。否则，输出
```
These sides do not correspond to a valid triangle
```
### 输入样例1：
```
5 5 3
```
### 输出样例1：
```
area = 7.15; perimeter = 13.00
```
### 输入样例2：
```
1 4 1
```
### 输出样例2：
```
These sides do not correspond to a valid triangle
```