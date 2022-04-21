#include <stdio.h>
int main(void)
{
    int count;
    for(int i=1;i<=100;i++){
        count=0;
        for(int j=2;j<=i;j++){
            if(i%j==0){
                count++;
            }
        }
        if(count==1){
            printf("%d 是质数\n",i);
        }
    }

    return 0;
}