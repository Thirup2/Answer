#include <stdio.h>
#define YJ 2.05     //洋蓟售价(美元/磅)
#define TC 1.15     //甜菜售价
#define HLB 1.09    //胡萝卜售价
#define FLOOR 100
#define RATE 0.05
#define ONE 6.5
#define TWO 14
#define THR 0.5
#define FIVE 5
#define TWE 20
void showmenu(void);
int main(void)
{
    double zbang1=0;double zbang2=0;double zbang3=0;double zbang;
    double bang1=0;double bang2=0;double bang3=0;
    double sum1=0;double sum2=0;double sum3=0;double sum=0;
    double zhe;double zhehou;
    double yun;
    char ch;
    showmenu();
    while((ch=getchar())!='q'){//获取各商品磅数
        printf("请输入商品磅数:");
        switch (ch)
        {
        case 'a':
            scanf("%lf",&bang1);
            zbang1+=bang1;
            break;
        case 'b':
            scanf("%lf",&bang2);
            zbang2+=bang2;
            break;
        case 'c':
            scanf("%lf",&bang3);
            zbang3+=bang3;
            break;
        }
        while(getchar()!='\n'){//抛弃其余输入
            continue;
        }
        printf("请选择商品:");
    }
    sum1=zbang1*YJ;//洋蓟总价
    sum2=zbang2*TC;//甜菜总价
    sum3=zbang3*HLB;//胡萝卜总价
    sum=sum1+sum2+sum3;//合计总价
    if(sum>=FLOOR){//计算折扣
        zhe=sum*RATE;
        zhehou=sum-zhe;
    }else{
        zhe=0;
        zhehou=sum;
    }
    zbang=zbang1+zbang2+zbang3;//总磅数
    if(zbang<=FIVE){//计算运费
        yun=ONE;
    }else if(zbang<=TWE){
        yun=TWO;
    }else{
        yun=TWO+(zbang-TWE)*THR;
    }
    printf("%-20s%-20s%-20s%-20s%-20s%-20s%-20s\n","商品","单价","磅数","单目总价","折扣","运费","总价");
    printf("%-20s%-18g%-18g%-16g%-18s%-18s%-20s\n","洋蓟",YJ,zbang1,sum1,"----","----","----");
    printf("%-20s%-18g%-18g%-16g%-18s%-18s%-20s\n","甜菜",TC,zbang2,sum2,"----","----","----");
    printf("%-21s%-18g%-18g%-16g%-18s%-18s%-20s\n","胡萝卜",HLB,zbang3,sum3,"----","----","----");
    printf("%-20s%-18s%-18g%-16g%-18g%-18g%-20g\n","合计","----",zbang,sum,zhe,yun,zhehou+yun);
    
    return 0;
}
void showmenu(void)
{
    printf("*****************************************************\n");
    printf("请选择商品:\n");
    printf("a) 洋蓟                        b) 甜菜\n");
    printf("c) 胡萝卜                      q) 退出订购\n");
    printf("*****************************************************\n");
}