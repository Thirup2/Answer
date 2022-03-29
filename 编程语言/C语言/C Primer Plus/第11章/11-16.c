#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 256
void print_orig(char * st);
void print_upper(char * st);
void print_lower(char * st);

int main(int argc,char *argv[])
{
    char c;
    if(argc<2){
        c='p';
    }else{
        c=argv[1][1];
    }
    char test[SIZE];
    printf("Enter a string to convert:");
    fgets(test,SIZE,stdin);
    switch(c){
        case 'p':
        case 'P':
            print_orig(test);
            break;
        case 'u':
        case 'U':
            print_upper(test);
            break;
        case 'l':
        case 'L':
            print_lower(test);
            break;
    }
    return 0;
}
void print_orig(char *st)
{
    printf("The original text is:\n%s",st);
}
void print_upper(char *st)
{
    printf("The upper case text is:\n");
    while(*st!=EOF&&*st!='\0'){
        putchar(toupper(*st++));
    }
}
void print_lower(char *st)
{
    printf("The lower case text is:\n");
    while(*st!=EOF&&*st!='\0'){
        putchar(tolower(*st++));
    }
}