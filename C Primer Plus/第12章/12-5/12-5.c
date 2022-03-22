#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100
void sort(int array[],int n);
int main(void)
{
    int date[SIZE];
    srand((unsigned int)time(0));
    for(int i=0;i<SIZE;i++){
        date[i]=rand()%10+1;
    }
    printf("原始数组是:");
    for(int i=0;i<SIZE;i++){
        printf("%4d",date[i]);
    }
    printf("\n");

    sort(date,SIZE);
    printf("现在的数组内容是:");
    for(int i=0;i<SIZE;i++){
        printf("%4d",date[i]);
    }
    printf("\n");

    return 0;
}
void sort(int array[],int n)
{
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(array[i]<array[j]){
                temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
}