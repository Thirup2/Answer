#include <stdio.h>
void menu(void);
double basic_rate(char);
int main(void)
{
    double hours;
    double basic;
    double money,get;
    double rate;
    char choice;
    menu();
    scanf("%c",&choice);
    basic=basic_rate(choice);
    if(basic!=-1){
        printf("请输入一周工作的小时数:");
        scanf("%lf",&hours);
        if(hours>0&&hours<=40){
            money=hours*basic;
        }else{
            money=40*basic+(hours-40)*1.5*basic;
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
    }else{
        printf("Bye\n");
    }
    
    return 0;
}
void menu(void)
{
    printf("******************************************************************\n");
    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("a) $8.75/hr                        b) $9.33/hr\n");
    printf("c) $10.00/hr                       d) $11.20/hr\n");
    printf("q) quit\n");
    printf("******************************************************************\n");
}
double basic_rate(char n)
{
    double rate;
    switch(n){
        case 'a':
            rate=8.75;
            break;
        case 'b':
            rate=9.33;
            break;
        case 'c':
            rate=10.00;
            break;
        case 'd':
            rate=11.20;
            break;
        case 'q':
            rate=-1;
            break;
    }
    return rate;
}