# Average
You are going to read a serial of none-negative integers, which ends with a negative number that does not count as one of the data. Your program calculates the average of all the none-negative integers, and prints the average which rounds to two decimal places.

When there's no valid data at all, your program prints out:

`None`

### 输入格式：
A serial of none-negative integers, ending with a negative number, which is not one of the valide data.

### 输出格式：
A number rounds to two decimal places, which is the average of the serial.

The printf for this case is:

`printf("%.2f\n", (double)sum/count);`

### 输入例子
```
1 2 3 4 5 6 -1
```
### 输出例子
```
3.50
```