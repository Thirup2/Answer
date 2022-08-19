#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 100

void select(int data[],int length,int n);
int main(void)
{
    int test[SIZE],number;
    printf("Enter number to selected.");
    scanf("%d",&number);
    for(int i=0;i<SIZE;i++){
        test[i]=i;
    }
    select(test,SIZE,number);
    return 0;
}
void select(int data[],int length,int n)
{
    srand((unsigned long)clock());
    printf("Start to select Number.\n");
    int * marks=(int *)malloc(length*sizeof(int));
    int index;
    while(n>0){
        index=rand()%length;
        if(marks[index]!=0){
            continue;
        }else{
            marks[index]=1;
        }
        printf("Selected ID: %3d DATA: %3d \n",index,data[index]);
        n--;
    }
}