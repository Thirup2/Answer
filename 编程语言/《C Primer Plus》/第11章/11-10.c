#include <stdio.h>
#include <string.h>
#define SIZE 80
char *trim_str(char *st);
int main(void)
{
    char test_string[SIZE];
    char *p=NULL;
    printf("Enter a string (blank to quit.):");
    fgets(test_string,SIZE,stdin);
    while(*test_string!='\n'){
        p=trim_str(test_string);
        printf("Done!\nNow the trim string is :");
        printf("%s\n",test_string);
        printf("Another? Enter a string (blank to quit):");
        fgets(test_string,SIZE,stdin);
    }

    return 0;
}
char *trim_str(char *st)
{
    char *head=st;
    int count =0;
    while(*st!='\0'){
        if(*st!=' '){
            *head++=*st++;
        }else{
            st++;
            count++;
        }
    }
    while(count--){
        *head++='\0';
    }
    return st;
}