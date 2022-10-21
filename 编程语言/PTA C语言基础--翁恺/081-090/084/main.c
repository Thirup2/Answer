#include<stdio.h>
#include<math.h>
int prime(int n)// 判断素数
{
    int i;
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return 0;//返回0不为素数
    }
    return 1;//返回1为素数
}
int main()
{
    long long n, i, j;
    scanf("%lld", &n);
    int start = 0, l = 0;
    long long s = 1;
    //特判：如果n为素数，则只有因数1和n
    if (prime(n))
        printf("1\n%d\n", n);
    else {
        //i遍历只需遍历到根号n即可，i为连续因子的左端，最大遍历到根号n
        //因为根号n乘根号n等于n，左端为根号n，继续往后遍历，下一个数就是根号n+1，相乘大于n
        //存在开出的根号n乘根号n不等于n的情况，遍历到根号n就可以了
        for (i = 2; i <= sqrt(n); i++) {
            s = 1;//s记录乘积
            //i确定连续因子的左端，j滑动确定右端
            for (j = i; s * j <= n; j++) {
                s = s * j;
                //l记录连续因子序列的长度
                //n%s==0是找到满足条件的连续因子序列并且此时长度大于原来的则更新长度
                //eg:连续因子不是所有数都要连一起的，如题所说，630=3*5*6*7，
                //当找到5*6这个连续序列时，n%s等于0,且长度可以更新为2，
                //继续遍历，发现5*6*7这个连续序列也满足，同时还可以将长度更新为3
                if (n % s == 0 && j - i + 1 > l) {
                    start = i;//记录连续序列左端点
                    l = j - i + 1;//不断更新l的值，求出最大的l
                }
            }
        }
        printf("%d\n", l);
        //按照输出格式输出，连续因子 最长序列的开始点为start，长度为l
        for (i = start; i < start + l; i++) {
            if (i == start)
                printf("%lld", i);
            else
                printf("*%lld", i);
        }
        printf("\n");
    }
    return 0;
}