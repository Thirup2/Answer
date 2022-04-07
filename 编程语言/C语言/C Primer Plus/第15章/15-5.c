#include <stdio.h>
#include <limits.h>
int rotate_l(int n,int length);
int main(int argc,char *argv[])
{
    int i,length;
    printf("Enter the a number and a move bit:");
    scanf("%d %d",&i,&length);
    printf("the %d move  %d bit, result is %d\n",i,length,rotate_l(i,length));
    return 0;
}
int rotate_l(int n,int length)
{
    const static int size=CHAR_BIT*sizeof(int);
    if(length>size||length<0){
        printf("Error length.\n");
        return 0;
    }
    for(int i=0;i<length;i++){
        if(n&(1<<(size-1))){
            n<<=1;
            n|=1;
        }else{
            n<<=1;
        }
    }
    return n;
}