#include <stdio.h>
void a(int n,int m,double source[n][m]);
double b(int n,double source[n]);
double c(int n,int m,double source[n][m]);
double d(int n,int m,double source[n][m]);
void e(int n,int m,double source[n][m]);
int main(void)
{
    int ROW=3;
    int COL=5;
    double source[ROW][COL];
    a(ROW,COL,source);
    printf("计算每组的平均值\n");
    for(int i=0;i<ROW;i++){
        printf("第%d组的平均值是:%g\n",i+1,b(COL,source));
    }
    printf("计算所有数据的平均值\n");
    printf("所有数据的平均值是:%g\n",c(ROW,COL,source));
    printf("找出数据中最大值\n");
    printf("数据中的最大值是:%g\n",d(ROW,COL,source));
    e(ROW,COL,source);

    return 0;
}
void a(int n,int m,double source[n][m])
{
    for(int i=0;i<n;i++){
        printf("请输入第%d组数据(每组数据5个数):",i+1);
        for(int j=0;j<m;j++){
            scanf("%lf",&source[i][j]);
        }
    }
}
double b(int n,double source[n])
{
    double average;
    double sum=0;
    for(int i=0;i<n;i++){
        sum+=source[i];
    }
    average=sum/n;
    return average;
}
double c(int n,int m,double source[n][m])
{
    double sum=0;
    double average;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            sum+=*(*(source+i)+j);
        }
    }
    average=sum/(n*m);
    return average;
}
double d(int n,int m,double source[n][m])
{
    double max;
    max=*(*source);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(max<*(*(source+i)+j)){
                max=*(*(source+i)+j);
            }
        }
    }
    return max;
}
void e(int n,int m,double source[n][m])
{
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("source[%d][%d]=%-10g",i,j,source[i][j]);
        }
        printf("\n");
    }
}