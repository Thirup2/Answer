#include <stdio.h>
int main(void)
{
    int n;
    int count1,count2;
    int sum1,sum2;
    count1=0;count2=0;
    sum1=0;sum2=0;
    while(scanf("%d",&n)==1&&n!=0){
        if(n%2==0){
            count2++;
            sum2+=n;
        }else{
            count1++;
            sum1+=n;
        }
    }
    printf("一共有%d个偶数,平均值是:%g\n",count2,1.0*sum2/count2);
    printf("一共有%d个奇数,平均值是:%g\n",count1,1.0*sum1/count1);

    return 0;
}