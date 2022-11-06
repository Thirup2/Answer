#include <stdio.h>
int StartHeart(int nums);           // 返回输入值的初心值, 若不是初心数则返回0
int BitSum(int nums);               // 返回参数各位和
int main(void)
{
    int nums;
    int N;
    int r;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &nums);
        r = StartHeart(nums);
        if (r) {
            printf("%d\n", r);
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
int StartHeart(int nums)
{
    int timed;
    timed = 2 * nums;
    int sum = BitSum(timed);
    for (int i = 3; i <= 9; i++) {              // 只要出现位和不相等的结果就输出0
        timed = i * nums;
        if (sum != BitSum(timed)) {
            return 0;
        }
    }
    return sum;                                 // 所有结果都相等就返回这个初心值
}
int BitSum(int nums)
{
    int sum = 0;
    while (nums != 0) {
        sum += nums % 10;
        nums /= 10;
    }
    return sum;
}