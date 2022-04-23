#include <stdio.h>
#define BPB 8           //一字节8位
int main(void)
{
    float mbps,mb,time;
    printf("请输入下载速度(Mb/s)和文件大小(MB):\n");
    while(scanf("%f %f",&mbps,&mb)==2){
        printf("At %.2f megabits per second, a file of %.2f megabytes\n",mbps,mb);
        printf("downloads in %.2f seconds.\n",mb*BPB/mbps);
        printf("请输入下载速度(Mb/s)和文件大小(MB):\n");
    }
    
    return 0;
}