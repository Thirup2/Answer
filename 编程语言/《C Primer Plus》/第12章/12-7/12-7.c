#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "diceroll.h"
int main(void)
{
    int dice,roll;
    int sides;
    int set;
    
    srand((unsigned int) time(0));
    printf("Enter the number of sets; enter q to stop : ");
    while (scanf("%d",&set)==1&&set>0)
    {
        printf("How many sides and how many dice? ");
        if(scanf("%d %d",&sides,&dice)==2&&sides>0&&dice>0){
            printf("Here are %d sets of %d %d-sided throws.\n",set,dice,sides);
            for(int i=0;i<set;i++){
                roll=roll_n_dice(dice,sides);
                printf("%d ",roll);
            }
            set=0;
            putchar('\n');
        }
        printf("Enter the number of sets; enter q to stop :");
    }
    printf("GOOD FORTUNE TO YOU!\n");
    
    return 0;
}