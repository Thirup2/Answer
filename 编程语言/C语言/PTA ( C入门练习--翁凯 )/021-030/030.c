#include <stdio.h>
void prit(int,int);
int main(void)
{
    int num;
    int count=0;
    scanf("%d",&num);
    if(num>0){
        prit(num,count);
    }else if(num<0){
        printf("fu ");
        num=-num;
        prit(num,count);
    }else{
        printf("ling");
    }

    return 0;
}
void prit(int num,int count)
{
    count++;
    int leave;
    leave=num;
    int some;
    some=leave%10;
    leave=leave/10;
    if(leave!=0){
        prit(leave,count);
    }
    switch(some){
        case 0:
            printf("ling");
            break;
        case 1:
            printf("yi");
            break;
        case 2:
            printf("er");
            break;
        case 3:
            printf("san");
            break;
        case 4:
            printf("si");
            break;
        case 5:
            printf("wu");
            break;
        case 6:
            printf("liu");
            break;
        case 7:
            printf("qi");
            break;
        case 8:
            printf("ba");
            break;
        case 9:
            printf("jiu");
            break;
    }
    if(count!=1){
        printf(" ");
    }
}