/*
** 本题其他地方题目中都有提及, 唯一一个题目中没提及但会检测的点是:
** 当一个序列同时包含负数和0时, 程序应该将连续0的子序列当作最大子序列, 也就是三者都输出0;
** 而当一个序列只存在负数时, 程序应该判定无最大子序列, 此时最大子序列和定义为0, 起始点和结束点分别为整个序列的起始点和结束点
*/
#include <stdio.h>
#include <stdlib.h>
struct ret
{
    int maxmum;     // 最大子列和
    int start;      // 最大子列开始处
    int end;        // 最大子列结束处
};                  // 输出结构
typedef struct ret RetType;
RetType Maximum(int a[], int x);        // 为了节省空间, 可以增加一个指向上述结构体的指针作为返回, 既不用返回实体也不必在函数中创建实体
int main(void)
{
    int K;
    scanf("%d", &K);
    int *a = (int *) malloc(K * sizeof(int));
    if (!a) {
        exit(EXIT_FAILURE);
    }
    int n;
    for (int i = 0; i < K; i++) {
        scanf("%d", &n);
        a[i] = n;
    }
    RetType max;
    max = Maximum(a, K);
    free(a);
    printf("%d %d %d\n", max.maxmum, max.start, max.end);
    return 0;
}
RetType Maximum(int a[], int x)
{
    int thissum = 0;                    // 保存当前子列和
    int thispos = 0;                    // 保存当前子列起始点

    // 创建保存数据的结构并初始化
    RetType max;
    max.maxmum = 0;
    max.start = a[0];
    max.end = a[0];
    
    int flag = 0;                       // 判断当前子列的起始点是否已保存
    int zero = 0;                       // 判断一个数组中是否含有0
    for (int i = 0; i < x; i++) {
        if (a[i] == 0 && zero == 0) {   // 如果数组含0就更改zero为1
            zero = 1;
        }

        // 在线处理计算最大子列和
        thissum += a[i];
        if (thissum < 0) {              // 当当前子列需要被丢弃时, 将当前子列和重置为0, 并更改flag状态
            thissum = 0;
            flag = 0;
        } else {
            if (flag == 0) {            // 当当前子列和开始累积时保存起始位置, 并更改flag状态
                thispos = a[i];
                flag = 1;
            }
        }
        if (thissum > max.maxmum) {     // 当当前子列和大于之前的最大子列和时, 更新最大子列和, 并更新起始点
            max.maxmum = thissum;
            max.start = thispos;
            max.end = a[i];             // 每次更新最大子列和时, 都将当前位置保存为最大子列的结束位置
        }
    }
    if (max.maxmum == 0) {              // 该条件包含两个需要区分的状态, 一是包含0但无正数, 一是全是负数
        max.end = a[x - 1];             // 若全是负数, 则打印首尾两个位置的数
        if (zero == 1) {                // 若包含0, 则全打印0
            max.start = 0;
            max.end = 0;
        }
    }
    return max;
}