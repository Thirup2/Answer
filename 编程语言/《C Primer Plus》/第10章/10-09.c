#include <stdio.h>
#define ONE 3
#define TWO 5
void copy_one(int n,int m,const double source[n][m],double target[n][m]);
void show_array(int n,int m,const double array[n][m]);
int main(void)
{
    const double source[ONE][TWO]={
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13.5,14,15}
    };
    double target[ONE][TWO];
    copy_one(ONE,TWO,source,target);
    show_array(ONE,TWO,source);
    show_array(ONE,TWO,target);
    

    return 0;
}
void copy_one(int n,int m,const double source[n][m],double target[n][m])
{
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            target[i][j]=source[i][j];
        }
    }
}
void show_array(int n,int m,const double array[n][m])
{
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%5g",array[i][j]);
        }
        printf("\n");
    }
}