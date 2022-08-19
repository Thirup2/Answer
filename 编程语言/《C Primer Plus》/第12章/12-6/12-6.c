#include <stdio.h>
#include <stdlib.h>
#define SIDES 10
#define TIMES 1000
int main(void)
{
    int date_count[SIDES];
    int date;
    for(int i=0;i<SIDES;i++){
        printf("这是第%d次创建数据\n",i+1);
        srand(i);
        for(int j=0;j<SIDES;j++){
            date_count[j]=0;
        }
        for(int j=0;j<TIMES;j++){
            date=rand()%SIDES+1;
            date_count[date-1]++;
        }
        printf("数据出现次数如下:\n");
        for(int j=0;j<SIDES;j++){
            printf("数字 %d 出现了 %d 次\n",j+1,date_count[j]);
        }
    }

    return 0;
}