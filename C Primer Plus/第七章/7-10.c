#include <stdio.h>
void showmenu(void);
int flor(int);
int main(void)
{
    double money;
    double rate;
    int choice;
    int floor;
    char ch;
    showmenu();
    scanf("%d",&choice);
    floor=flor(choice);
    while(floor!=-1){
        printf("请输入您的工资:");
        scanf("%lf",&money);
        if(money>floor){
            rate=floor*0.15+(money-floor)*0.28;
        }else{
            rate=money*0.15;
        }
        printf("您应该缴纳的税金是:%lf\n",rate);
        showmenu();
        scanf("%d",&choice);
        floor=flor(choice);
    }
    printf("Done\n");

    return 0;
}
void showmenu(void)
{
    printf("***************************************************\n");
    printf("请选择您所属的档次:\n");
    printf("1) 单身             2) 户主\n");
    printf("3) 已婚             4) 离异\n");
    printf("5) 退出\n");
    printf("***************************************************\n");
}
int flor(int n)
{
    int rate;
    switch (n)
    {
    case 1:
        rate=17850;
        break;
    case 2:
        rate=23900;
        break;
    case 3:
        rate=29750;
        break;
    case 4:
        rate=14875;
        break;
    case 5:
        rate=-1;
        break;
    }
    return rate;
}