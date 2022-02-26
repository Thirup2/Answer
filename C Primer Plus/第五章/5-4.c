#include <stdio.h>
#define C_F 30.48       //一英尺30.48厘米
#define F_I 12          //一英尺12英寸
int main(void)
{
    //定义值
    double cm,in;
    int feet;

    //获取值
    printf("Enter a height in centimeters:");
    while(scanf("%lf",&cm)==1&&cm>0){
        in=cm/C_F*F_I;
        feet=in/F_I;
        in=in-feet*F_I;
        printf("%.1lf cm = %d feet, %.1lf inches\n",cm,feet,in);
        printf("Enter a height in centimeters (<=0 to quit):");
    }
    //循环结束
    printf("bye\n");

    //函数返回值
    return 0;
}