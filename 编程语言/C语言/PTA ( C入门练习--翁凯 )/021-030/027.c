#include <stdio.h>
int main(void)
{
    int month=1;
    int rubbit_1=1;
    int rubbit_2=0;
    int rubbit_old=0;
    int sum=1;
    int aim;
    scanf("%d",&aim);
    if(aim>=1&&aim<=10000){
        while(sum<aim){
            month++;
            rubbit_old+=rubbit_2;
            rubbit_2=rubbit_1;
            rubbit_1=rubbit_old;
            sum=rubbit_1+rubbit_2+rubbit_old;
        }
        printf("%d",month);
    }

    return 0;
}