#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char ch;
    signed char checksum=-1;
    while((ch=getchar())!=EOF){
        checksum+=ch;
    }
    printf("%d\n",checksum);

    return EXIT_SUCCESS;
}