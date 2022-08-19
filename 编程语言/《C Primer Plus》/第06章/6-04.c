#include <stdio.h>
#define ROWS 6
int main(void)
{
    char ch='A';
    int i,j;
    for(i=1;i<=ROWS;i++){
        for(j=1;j<=i;j++,ch++){
            printf("%c",ch);
        }
        printf("\n");
    }

    return 0;
}