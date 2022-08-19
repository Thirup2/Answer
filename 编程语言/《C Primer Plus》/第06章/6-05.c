#include <stdio.h>
#define ROWS 5
int main(void)
{
    int ch;;
    for(int i=0;i<ROWS;i++){
        for(int j=4;j>i;j--){
            printf(" ");
        }
        for(int j=0,ch='A';j<i;j++,ch++){
            printf("%c",ch);
        }
        for(int j=0,ch='A'+i;j<=i;j++,ch--){
            printf("%c",ch);
        }
        printf("\n");
    }

    return 0;
}