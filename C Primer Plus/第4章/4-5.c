#include <stdio.h>
#define BPB 8           //一字节8位
int main(void)
{
    //定义值
    float mbps,mb,time;

    //获取值
    printf("请输入文件大小(MB):");
    scanf("%f",&mb);
    printf("接下来请输入文件传输速度(Mb/s):");
    scanf("%f",&mbps);

    //计算值
    time = mb * BPB / mbps;

    //打印值
    printf("At %.2f megabits per second, a file of %.2f megabytes\ndownloads in %.2f seconds.\n",mbps,mb,time);

    //函数返回值
    return 0;
}