#include <stdio.h>
#define TH 3
#define FI 5
void dou(double (*source)[FI],int n);
void show_arr(double (*source)[FI],int n);
int main(void)
{
    double source[TH][FI]={
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15}
    };
    show_arr(source,TH);
    dou(source,TH);
    show_arr(source,TH);

    return 0;
}
void dou(double (*source)[FI],int n)
{
    for(int i=0;i<n;i++){
        for(int j=0;j<FI;j++){
            *(*(source+i)+j)=*(*(source+i)+j)*2;
        }
    }
}
void show_arr(double (*source)[FI],int n)
{
    for(int i=0;i<n;i++){
        for(int j=0;j<FI;j++){
            printf("%5g",*(*(source+i)+j));
        }
        printf("\n");
    }
}