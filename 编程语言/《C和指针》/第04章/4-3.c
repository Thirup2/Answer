#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    float a,b,c;
    float max,mid,min;
    printf("请输入三角形三边的长度:\n");
    scanf("%f %f %f",&a,&b,&c);
    if(a<=b){
        if(a<=c){
            min=a;
            if(b<=c){
                mid=b;
                max=c;
            }else{
                mid=c;
                max=b;
            }
        }else{
            min=c;
            mid=a;
            max=b;
        }
    }else{
        if(a>=c){
            max=a;
            if(b>=c){
                mid=b;
                min=c;
            }else{
                mid=c;
                min=b;
            }
        }else{
            max=c;
            mid=a;
            min=b;
        }
    }
    if(min+mid<=max){
        printf("你所输入的三边长度无法构成三角形\n");
        exit(EXIT_FAILURE);
    }
    if(min==mid&&min==max){
        printf("这是一个等边三角形\n");
    }else if(min==mid||max==mid){
        printf("这是一个等腰三角形\n");
    }
    if(min!=mid&&min!=max&&mid!=max){
        printf("这是一个不等边三角形\n");
    }

    return EXIT_SUCCESS;
}