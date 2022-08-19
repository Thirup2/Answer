#include <stdio.h>
#include <string.h>
#define SIZE 80
char *invert_str(char *st);
int main(void)
{
    char test_string[SIZE];
    char *p=NULL;
    printf("Enter a string (enter to quit.):");
    fgets(test_string,SIZE,stdin);
    while(*test_string!='\n'){
        p=invert_str(test_string);
        printf("Done!\nNow the invert string is :");
        printf("%s\n",test_string);
        printf("Another? Enter a string (enter to quit.):");
        fgets(test_string,SIZE,stdin);
    }

    return 0;
}

char *invert_str(char *st)
{
    int length=strlen(st);
    char invert[length];
    for(int i=0;i<length;i++){
        *(invert+i)=*(st+length-1-i);
    }
    for(int i=0;i<length;i++){
        *(st+i)=*(invert+i);
    }
    return st;
}