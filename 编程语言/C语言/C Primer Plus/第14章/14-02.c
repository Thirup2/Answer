#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct month {
    char month_name[10];
    char month_abbrev[4];
    int days;
    int number;
} months[12]={
    {"January","Jan",31,1},
    {"February","Feb",28,2},
    {"March","Mar",31,3},
    {"April","Apr",30,4},
    {"May","May",31,5},
    {"June","Jun",30,6},
    {"July","Jul",31,7},
    {"August","Aug",31,8},
    {"September","Sep",30,9},
    {"October","Oct",31,10},
    {"November","Nov",30,11},
    {"December","Dec",31,12}
};
int cala_days(int year,int month,int day);
int isaspeyear(int year);
int trans_month(char *name);
int main(void)
{
    int day,year,month;
    char name[10];
    printf("请按以下格式输入: \n");
    printf("年/月(月份号/月份名/月份名缩写)/日\n");
    while(scanf("%d/%s/%d",&year,name,&day)!=3){
        printf("您输入的格式有误，请严格按照格式输入: ");
        while(getchar()!='\n'){
            continue;
        }
    }
    month=trans_month(name);
    while(year>0&&month>0&&month<=12&&day>0&&day<=31){
        printf("从%d年1月1日到%d年%d月%d日一共有%d天\n",year,year,month,day,cala_days(year,month,day));
        printf("请输入下一个日期\n");
        while(scanf("%d/%s/%d",&year,name,&day)!=3){
            printf("您输入的格式有误，请严格按照格式输入: ");
            while(getchar()!='\n'){
                continue;
            }
        }
        month=trans_month(name);
    }
    printf("Done.");

    return 0;
}
int trans_month(char *name)
{
    for(int i=0;i<12;i++){
        if(strcmp(name,months[i].month_name)==0||strcmp(name,months[i].month_abbrev)==0){
            return months[i].number;
        }else if(atoi(name)==months[i].number){
            return months[i].number;
        }
    }
    return 0;
}
int cala_days(int year,int month,int day)
{
    if(isaspeyear(year)!=0){
        months[1].days=29;
    }else{
        months[1].days=28;
    }
    int total=0;
    for(int i=0;i<12;i++){
        if((i+1)==month){
            total=total+day-1;
            return total;
        }else{
            total+=months[i].days;
        }
    }
    return -1;
}
int isaspeyear(int year)
{
    if(year%100==0){
        if(year%400==0){
            return 1;
        }else{
            return 0;
        }
    }else{
        if(year%4==0){
            return 1;
        }else{
            return 0;
        }
    }
}