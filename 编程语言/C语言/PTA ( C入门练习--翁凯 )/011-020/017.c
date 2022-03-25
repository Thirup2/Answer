#include <stdio.h>
int main(void)
{
    int p;
    scanf("%d",&p);
    if(p>=90&&p<=100){
        printf("A");
    }else if(p>=80){
        printf("B");
    }else if(p>=70){
        printf("C");
    }else if(p>=60){
        printf("D");
    }else if(p>=0){
        printf("E");
    }

    return 0;
}