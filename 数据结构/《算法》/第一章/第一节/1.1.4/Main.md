## 下列语句各有什么问题(如果有的话)?
### a.
```java
if (a > b) then c =0;
```
答: 不存在if-then语句

### b.
```java
if a > b { c = 0; }
```
答: 条件需要用括号括起来

### c.
```java
if (a > b) c = 0;
```
答: 无问题

### d.
```java
if (a > b) c = 0 else b = 0;
```
答: c = 0语句后需要一个分号