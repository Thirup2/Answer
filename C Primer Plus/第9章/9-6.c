#include <stdio.h>
void swap(double*,double*,double*);
int main(void)
{
    double a,b,c;
    printf("请输入三个数:");
    scanf("%lf %lf %lf",&a,&b,&c);
    swap(&a,&b,&c);
    printf("a = %g\nb = %g\nc = %g\n",c,b,a);

    return 0;
}
void swap(double *a,double *b,double *c)
{
    double x,y,z;
    x=*a;
    y=*b;
    z=*c;
    if(x>y){
        if(x>z){
            if(y<z){
                *b=z;
                *c=y;
            }
        }else{
            *a=z;
            *b=x;
            *c=y;
        }
    }else{
        if(y<z){
            *a=z;
            *c=x;
        }else{
            if(z>x){
                *a=y;
                *b=z;
                *c=x;
            }else{
                *a=y;
                *b=x;
            }
        }
    }
}
