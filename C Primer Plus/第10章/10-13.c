#include <stdio.h>
#define ROW 3
#define COL 5
void a(double (*source)[COL],int n);
double b(double *source,int n);
double c(double (*source)[COL],int n);
double d(double (*source)[COL],int n);
void e(double (*source)[COL],int n);
int main(void)
{
    double source[ROW][COL];
    a(source,ROW);
    printf("计算每组的平均值\n");
    for(int i=0;i<ROW;i++){
        printf("第%d组的平均值是:%g\n",i+1,b(*(source+i),COL));
    }
    printf("计算所有数据的平均值\n");
    printf("所有数据的平均值是:%g\n",c(source,ROW));
    printf("找出数据中最大值\n");
    printf("数据中的最大值是:%g\n",d(source,ROW));
    e(source,ROW);

    return 0;
}
void a(double (*source)[COL],int n)
{
    for(int i=0;i<n;i++){
        printf("请输入第%d组数据(每组数据5个数):",i+1);
        for(int j=0;j<COL;j++){
            scanf("%lf",&source[i][j]);
        }
    }
}
double b(double *source,int n)
{
    double average;
    double sum=0;
    for(int i=0;i<n;i++){
        sum+=source[i];
    }
    average=sum/n;
    return average;
}
double c(double (*source)[COL],int n)
{
    double sum=0;
    double average;
    for(int i=0;i<n;i++){
        for(int j=0;j<COL;j++){
            sum+=*(*(source+i)+j);
        }
    }
    average=sum/(n*COL);
    return average;
}
double d(double (*source)[COL],int n)
{
    double max;
    max=*(*source);
    for(int i=0;i<n;i++){
        for(int j=0;j<COL;j++){
            if(max<*(*(source+i)+j)){
                max=*(*(source+i)+j);
            }
        }
    }
    return max;
}
void e(double (*source)[COL],int n)
{
    for(int i=0;i<n;i++){
        for(int j=0;j<COL;j++){
            printf("source[%d][%d]=%-10g",i,j,source[i][j]);
        }
        printf("\n");
    }
}