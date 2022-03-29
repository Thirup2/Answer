#include <stdio.h>
#include <ctype.h>
#include <string.h>

int myatoi(char *st);
int main(int argc,char *argv[])
{
    char test[8];
    printf("Enter a number of int:");
    scanf("%s",test);
    printf("you input int is: %d\n",myatoi(test));
    return 0;
}
int myatoi(char *st)
{
    int result=0;
    int bit_mark=1;
    int length=strlen(st);
    for(int i=length;i>0;i--){
        if(isdigit(*(st+i-1))==0){
            printf("Error in character.\n");
            return 0;
        }
        result+=(*(st+i-1)-'0')*bit_mark;
        bit_mark*=10;
    }
    return result;
}