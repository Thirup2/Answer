#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void function_a(char c);
void function_b(char c);
void function_c(char c);
int main(int argc , char argv[])
{
    void (*pf[3])(char);
    pf[0]=function_a;
    pf[1]=function_b;
    pf[2]=function_c;
    char ch;
    printf("a) Function A.    b) Function B.    c) Function C.    q) Quit\n");
    scanf("%c",&ch);
    while(ch!='q'){
        while(getchar()!='\n'){
            continue;
        }
        switch(ch){
            case 'a':
                pf[0](ch);
                break;
            case 'b':
                pf[1](ch);
                break;
            case 'c':
                pf[2](ch);
                break;
            default:
                break;
        }
        printf("a) Function A.    b) Function B.    c) Function C.    q) Quit\n");
        printf("Enter a, b, c or q:");
        scanf("%c",&ch);
    }
    printf("Done!\n");
    return 0;
}
void function_a(char c)
{
    printf("This is function_a you select %c\n",c);
}
void function_b(char c)
{
    printf("This is function_b you select %c\n",c);
}
void function_c(char c)
{
    printf("This is function_c you select %c\n",c);
}