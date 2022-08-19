#include <stdio.h>
void ch(void);
void in(void);
void flo(void);
int main(void)
{
    int n;
    printf("请选择一个类型进行观察:\n");
    printf("1) 字符类型 2) 整数类型 3) 浮点类型 q) 退出\n");
    while(scanf("%d",&n)==1){
        switch (n){
            case 1:
                ch();
                break;
                //在调用ch()函数并进行多次试验后输入其他选项后进程死掉
            case 2:
                in();
                break;
            case 3:
                flo();
                break;
            default:
                printf("请输入正确的选项:\n");
                break;
        }
    }
    printf("bye!\n");

    return 0;
}
void ch(void)
{
    char ch; signed char ch_s; unsigned char ch_un;
    printf("please enter the range numbers of char type(q to quit):\n");
    while(scanf("%d",&ch)==1){
        printf("%d\n",ch);
    }
    while(getchar()!='\n'){
        continue;
    }
    printf("please enter the range numbers of signed char type (q to quit):\n");
    while(scanf("%d",&ch_s)==1){
        printf("%d\n",ch_s);
    }
    while(getchar()!='\n'){
        continue;
    }
    printf("please enter the range numbers of unsigned char type(q to quit):\n");
    while(scanf("%d",&ch_un)==1){
        printf("%d\n",ch_un);
    }
    while(getchar()!='\n'){
        continue;
    }
}
void in(void)
{
    short in_h; unsigned short in_uh;
    int in; unsigned int in_u;
    long in_l; unsigned long in_ul;
    long long in_ll; unsigned long long in_ull;
    printf("please enter the range numbers of short type(q to quit):\n");
    while(scanf("%hd",&in_h)==1){
        printf("%hd\n",in_h);
    }
    while(getchar()!='\n'){
        continue;
    }
    printf("please enter the range numbers of unsigned short type(q to quit):\n");
    while(scanf("%hu",&in_uh)==1){
        printf("%hu\n",in_uh);
    }
    while(getchar()!='\n'){
        continue;
    }
    printf("please enter the range numbers of int type(q to quit):\n");
    while(scanf("%d",&in)==1){
        printf("%d\n",in);
    }
    while(getchar()!='\n'){
        continue;
    }
    printf("please enter the range numbers of unsigned int type(q to quit):\n");
    while(scanf("%u",&in_u)==1){
        printf("%u\n",in_u);
    }
    while(getchar()!='\n'){
        continue;
    }
    printf("please enter the range numbers of long type(q to quit):\n");
    while(scanf("%ld",&in_l)==1){
        printf("%ld\n",in_l);
    }
    while(getchar()!='\n'){
        continue;
    }
    printf("please enter the range numbers of unsigned long type(q to quit):\n");
    while(scanf("%lu",&in_ul)==1){
        printf("%lu\n",in_ul);
    }
    while(getchar()!='\n'){
        continue;
    }
    printf("please enter the range numbers of long long type(q to quit):\n");
    while(scanf("%lld",&in_ll)==1){
        printf("%lld\n",in_ll);
    }
    while(getchar()!='\n'){
        continue;
    }
    printf("please enter the range numbers of unsigned long long type(q to quit):\n");
    while(scanf("%llu",&in_ull)==1){
        printf("%llu\n",in_ull);
    }
    while(getchar()!='\n'){
        continue;
    }
}
void flo(void)
{
    float flo; double dou; long double ldou;
    printf("please enter the range numbers of float type(q to quit):\n");
    while(scanf("%f",&flo)==1){
        printf("YourEnter * 10 = %.50f\n",flo*10);
        printf("YourEnter / 10 = %.50f\n",flo/10);
    }
    while(getchar()!='\n'){
        continue;
    }
    printf("please enter the range numbers of double type(q to quit):\n");
    while(scanf("%lf",&dou)==1){
        printf("YourEnter * 10 = %.50lf\n",dou*10);
        printf("YourEnter / 10 = %.50lf\n",dou/10);
    }
    while(getchar()!='\n'){
        continue;
    }
    printf("please enter the range numbers of long double type(q to quit):\n");
    while(scanf("%lf",&ldou)==1){
        printf("YourEnter * 10 = %.50lf\n",ldou*10);
        printf("YourEnter / 10 = %.50lf\n",ldou/10);
    }
    while(getchar()!='\n'){
        continue;
    }
}