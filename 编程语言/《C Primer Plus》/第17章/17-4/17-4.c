// mall.c -- use the Queue interface
// compile with queue.c
#include <stdio.h>
#include <stdlib.h>    // for rand() and srand()
#include <time.h>      // for time()
#include <stdbool.h>
#include "queue.h"     // change Item typedef
#define MIN_PER_HR 60.0

struct{
    Queue line;
    int hours,perhour,wait_time;
    long cycle,cyclelimit,turnaways;
    long customers,served,sum_line,line_wait;
    double min_per_cust;
}Booth_line[2];
bool newcustomer(double x);   // is there a new customer?
Item customertime(long when); // set customer parameters

int main(void)
{
    Item temp;
    InitializeQueue(&Booth_line[0].line);
    InitializeQueue(&Booth_line[1].line);
    srand((unsigned int )time(0));
    
    puts("Case Study: Sigmund Lander's Advice Booth");
    puts("Enter the number of simulation hours for queue1:");
    scanf("%d", &Booth_line[0].hours);
    Booth_line[0].cyclelimit = MIN_PER_HR * Booth_line[0].hours;
    puts("Enter the number of simulation hours for queue2:");
    scanf("%d", &Booth_line[1].hours);
    Booth_line[1].cyclelimit = MIN_PER_HR * Booth_line[1].hours;
    puts("Enter the average number of customers per hour for queue1:");
    scanf("%d", &Booth_line[0].perhour);
    Booth_line[0].min_per_cust=MIN_PER_HR/Booth_line[0].perhour;
    puts("Enter the average number of customers per hour for queue2:");
    scanf("%d", &Booth_line[1].perhour);
    Booth_line[1].min_per_cust=MIN_PER_HR/Booth_line[1].perhour;
    
    for(int i=0;i<2;i++){
        for(Booth_line[i].cycle=0;Booth_line[i].cycle<Booth_line[i].cyclelimit;Booth_line[i].cycle++){
            if(newcustomer(Booth_line[i].min_per_cust)){
                if(QueueIsFull(&Booth_line[i].line)){
                    Booth_line[i].turnaways++;
                }else{
                    Booth_line[i].customers++;
                    temp=customertime(Booth_line[i].cycle);
                    EnQueue(temp,&Booth_line[i].line);
                }
            }
            if(Booth_line[i].wait_time<=0&&!QueueIsEmpty(&Booth_line[i].line)){
                DeQueue(&temp,&Booth_line[i].line);
                Booth_line[i].wait_time=temp.processtime;
                Booth_line[i].line_wait+=Booth_line[i].cycle-temp.arrive;
                Booth_line[i].served++;
            }
            if(Booth_line[i].wait_time>0){
                Booth_line[i].wait_time--;
            }
            Booth_line[i].sum_line+=QueueItemCount(&Booth_line[i].line);
        }
        if(Booth_line[i].customers>0){
            printf("customers accepted for queue%d:%ld\n",i+1,Booth_line[i].customers);
            printf("customers served for queue%d:%ld\n",i+1,Booth_line[i].served);
            printf("turnaways for queue%d:%ld\n",i+1,Booth_line[i].turnaways);
            printf("average wait time for queue%d:%.2f minutes\n",i+1,(double)Booth_line[i].line_wait/Booth_line[i].served);
        }else{
            printf("No customers for queue%d!",i+1);
        }
        EmptyTheQueue(&Booth_line[i].line);
    }

    return 0;
}

// x = average time, in minutes, between customers 
// return value is true if customer shows up this minute
bool newcustomer(double x)
{
    if (rand() * x / RAND_MAX < 1)
        return true;
    else
        return false;
}

// when is the time at which the customer arrives
// function returns an Item structure with the arrival time
// set to when and the processing time set to a random value
// in the range 1 - 3
Item customertime(long when)
{
    Item cust;
    
    cust.processtime = rand() % 3 + 1;
    cust.arrive = when;
    
    return cust;
}
