#include <stdio.h>
#include <stdlib.h>
int SumOfRange(unsigned low, unsigned up);            // 左开右闭
int IsItPrime(unsigned num);
int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("请输入两个参数，第一个参数为上限，第二个参数为间隔!\n");
        return -1;
    }
    unsigned int max = (unsigned int) atoi(argv[1]);
    unsigned int gap = (unsigned int) atoi(argv[2]);
    int sum;
    unsigned max_in;
    for (int i = 0; i < max; i += gap) {
        if (i + gap > max) {
            max_in = max;
        } else {
            max_in = i + gap;
        }
        sum = SumOfRange(i, max_in);
        printf("%d~%d: %d\n", i, max_in, sum);
    }

    return 0;
}
int SumOfRange(unsigned low, unsigned up)
{
    int sum = 0;
    for (unsigned i = up; i > low; i--) {
        if (IsItPrime(i)) {
            sum++;
        }
    }
    return sum;
}
int IsItPrime(unsigned num)
{
    if (num == 1) {
        return 0;
    }
    for (unsigned i = num - 1; i > 1; i--) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}