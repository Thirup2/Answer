#include <stdio.h>
int main(void)
{
    int num;
    scanf("%d",&num);
    int fi,ho;
    if(num>=0&&num<=153){
        fi=num/16;
        ho=num%16;
        printf("%d",fi*10+ho);
    }

    return 0;
}