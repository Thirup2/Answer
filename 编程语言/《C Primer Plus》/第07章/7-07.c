#include <stdio.h>
#define MON 10      //10美元一小时
int main(void)
{
    double hours;
    double money,get;
    double rate;
    printf("请输入一周工作的小时数:");
    scanf("%lf",&hours);
    if(hours>0&&hours<=40){
        money=hours*MON;
    }else{
        money=40*MON+(hours-40)*1.5*MON;
    }
    if(money<=300){
        rate=money*0.15;
    }else if(money<=450){
        rate=300*0.15+(money-300)*0.2;
    }else{
        rate=300*0.15+150*0.2+(money-450)*0.25;
    }
    get=money-rate;
    printf("您一周工作%g小时\n所以您的工资总额是%g美元; 您所需缴纳的税金是%g美元; 所以您最后的净收入是%g美元",hours,money,rate,get);

    return 0;
}