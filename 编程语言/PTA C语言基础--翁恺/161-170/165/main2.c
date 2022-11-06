#include <stdio.h>              // 使用字符串实现的方案, 如果是更长的数字应该更有用
void times(char *num, char *timed, int times);          // 求num的倍数并把结果放入timed, 倍数为times
int bitsum(char *num);                                  // 求num各个位数上的和
int StarHeart(char *num);                               // 求初心值
int main(void)
{
    char nums[6];           // 保存输入值
    int N;
    int r;                  // 获取初心值函数的返回值
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s", nums);
        r = StarHeart(nums);        // 返回输入值的初心值, 若返回0则表示其不是一个初心数
        if (r) {
            printf("%d\n", r);
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
void times(char *num, char *timed, int times)       // 模拟乘法
{
    int i = 0;
    while (num[i] != '\0') {            // 将i移到num最后一个数字
        i++;
    }
    i--;
    int ten = 0;            // 模拟乘法中需要加入下一位的十位上的数字
    int bit;                // 模拟乘法中直接写到末尾的个位上的数字
    int tot;                // 一次乘法的值
    int j = 5;              // 将j移到timed末尾, 从此处开始写入
    while (i >= 0) {
        tot = (num[i] - '0') * times + ten;
        ten = tot / 10;
        bit = tot % 10;
        timed[j--] = bit + '0';
        i--;
    }
    if (ten > 0) {              // 将最后一个十位数字写入
        timed[j] = ten + '0';
    } else {
        j++;
    }
    i = 0;
    int z = j;
    if (j != 0) {                   // 将timed中保存下来的结果移动到数组开始位置
        while (i < 6 - j) {
            timed[i++] = timed[z++];
        }
    }
    timed[6 - j] = '\0';
}
int bitsum(char *num)
{
    int sum = 0;
    int i = 0;
    while (num[i] != '\0') {
        sum += num[i] - '0';
        i++;
    }
    return sum;
}
int StarHeart(char *num)
{
    char timed[6];
    times(num, timed, 2);
    int sum = bitsum(timed);
    for (int i = 3; i <= 9; i++) {              // 比较每个乘法结果, 如果存在一个结果的数字和与第一个不同, 就表示不是初心值
        times(num, timed, i);
        if (sum != bitsum(timed)) {
            return 0;
        }
    }
    return sum;                                 // 否则输出这个初心值
}