#include "pe12-2a.h"
static int mode;
static double range,fuel;

void set_mode(int n)
{
    if(n>1){
        printf("Invalid mode specified.");
        if(mode==0){
            printf(" Mode 0(Mrtric) used.\n");
        }else{
            printf(" Mode 1(US) used.\n");
        }
    }else{
        mode = n;
    }
}

void get_info(void)
{
    if(mode==0){
        printf("Enter distance traveled in kilometers:");
        scanf("%lf",&range);
        printf("Enter fuel consumed in liters:");
        scanf("%lf",&fuel);
    }else{
        printf("Enter distance traveled in miles:");
        scanf("%lf",&range);
        printf("Enter fuel consumed in gallons:");
        scanf("%lf",&fuel);
    }
}

void show_info(void)
{
    if(mode==0){
        printf("Fuel consumption is %.2lf liters per 100 km.\n",fuel/range*100);
    }else{
        printf("Fuel consumption is %.1lf miles per gallon.\n",range/fuel);
    }
}