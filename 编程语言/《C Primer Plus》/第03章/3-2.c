#include <stdio.h>
int main(void)
{
    int n;
    printf("please enter an ASCII code:\n");
    while(scanf("%d",&n)==1){
        printf("%c\n",n);
    }

    return 0;
}