#include <stdio.h>
static float a3,a2,a1,a0;
float f(float x);
int main(void)
{
    float a,b;
    scanf("%f %f %f %f\n%f %f",&a3,&a2,&a1,&a0,&a,&b);
    float left,right,mid;
    left=a;
    right=b;
    while(right-left>0.001){
        if(f(left)==0){
            printf("%.2f",left);
            return 0;
        }
        if(f(right)==0){
            printf("%.2f",right);
            return 0;
        }
        mid=(left+right)/2;
        if(f(left)*f(mid)>0){
            left=mid;
        }else if(f(right)*f(mid)>0){
            right=mid;
        }else{
            printf("%.2f",mid);
            return 0;
        }
    }
    printf("%.2f",(left+right)/2);
    return 0;
}
float f(float x)
{
    float fx;
    fx=a3*x*x*x+a2*x*x+a1*x+a0;
    return fx;
}