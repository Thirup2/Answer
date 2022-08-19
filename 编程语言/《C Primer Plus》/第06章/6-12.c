#include <stdio.h>
int main(void)
{
    unsigned long long times;
    double sum,sum1,sum2;
    double be= 1.0;
    printf("请输入运算次数:");
    scanf("%llu",&times);
    for(int i=0;i<times;i++){
        sum1+=1.0/(be+i);
    }
    for(int i=0;i<times;i++){
        if(i%2==0){
            sum2+=1.0/(be+i);
        }else{
            sum2-=1.0/(be+i);
        }
    }
    sum=sum1+sum2;
    printf("程序运行了%llu次\n序列1之和:%lf\n序列2之和:%lf\n两序列之和:%lf\n",times,sum1,sum2,sum);

    return 0;
}