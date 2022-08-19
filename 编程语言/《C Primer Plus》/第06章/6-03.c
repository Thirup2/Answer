#include <stdio.h>
#define F 'F'
#define ROWS 6
int main(void)
{
    char ch;
    int i,j;
    for(i=1;i<=ROWS;i++){
        for(ch=F,j=1;j<=i;j++,ch--){
            printf("%c",ch);
        }
        printf("\n");
    }

    return 0;
}