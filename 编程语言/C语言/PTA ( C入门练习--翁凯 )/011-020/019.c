#include <stdio.h>
int main(void)
{
    int days[12]={31,[2]=31,30,31,30,31,31,30,31,30,31};
    int yyyy,mm,dd;
    int sum;
    scanf("%d/%d/%d",&yyyy,&mm,&dd);
    if(yyyy%4==0){
        if(yyyy%100==0){
            if(yyyy%400==0){
                days[1]=29;
            }else{
                days[1]=28;
            }
        }else{
            days[1]=29;
        }
    }else{
        days[1]=28;
    }
    for(int i=0;i<mm-1;i++){
        sum+=days[i];
    }
    sum+=dd;
    printf("%d",sum);
}