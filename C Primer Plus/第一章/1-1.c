//项目要求:需要一个把英寸单位转换为厘米单位的程序.
//要求1:提示用户输入英寸值
#include <stdio.h>
#define SWAP 2.54       //一英寸 = 2.54厘米
int main(void)
{
    //定义值
    double length,c_length;

    //获取值
    printf("请输入一个长度(英寸):( <= 0 to quit )");
    while(scanf("%lf",&length)==1&&length>0){
        c_length=length*SWAP;
        printf("%g英寸 = %g厘米\n",length,c_length);
        printf("请输入一个长度(英寸):( <= 0 to quit )");
    }
    /*当输入小于零的值时应该输出让用户重新输入的话,并重新获取输入*/
    /*当输入非数字时应让用户重新输入,并重新获取输入*/
    /*当且仅当用户输入q时,程序结束*/

    //函数返回值
    return 0;
}