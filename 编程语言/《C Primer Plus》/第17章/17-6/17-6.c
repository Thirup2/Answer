#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20

int comp(const void *,const void *);
int bfind(const int array[],int size,int targ);

int main(void)
{
    int numbers[SIZE];
    int result, input;

    srand(time(0));
    for(int i=0;i<SIZE;i++){
        numbers[i]=rand()%100;
    }
    puts("There are UNSORTED numbers list :");
    for(int i=0;i<SIZE;i++){
        printf(" %d",numbers[i]);
    }
    putchar('\n');
    qsort(numbers,SIZE,sizeof(int),comp);

    puts("There are SORTED numbers list :");
    for(int i=0;i<SIZE;i++){
        printf(" %d",numbers[i]);
    }
    putchar('\n');

    puts("Input which number you want to find:");
    scanf("%d",&input);
    if(bfind(numbers,SIZE,input)==1){
        printf("find it!\n");
    }else{
        printf("Do not find it!\n");
    }
    return 0;
}
int comp(const void *p1,const void *p2)
{
    const int *ps1=(const int *)p1;
    const int *ps2=(const int *)p2;

    if(*ps1>*ps2){
        return 1;
    }else if(*ps1==*ps2){
        return 0;
    }else{
        return -1;
    }
}
int bfind(const int array[],int size,int targ)
{
    int cur,low=0;
    int high=size-1;
    while(low<=high){
        cur=(high+low)/2;
        if(targ==array[cur]){
            return 1;
        }
        if(targ>array[cur]){
            low=cur+1;
        }else{
            high=cur-1;
        }
        if(cur==low){
            return 0;
        }
    }
    return 0;
}