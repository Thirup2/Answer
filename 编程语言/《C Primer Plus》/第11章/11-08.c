#include <stdio.h>
#include <string.h>
#define SIZE 80
char *string_in(char *st,char *sub);
int main(void)
{
    char main_string[SIZE],sub[SIZE];
    char *p=NULL;
    printf("Enter a String as main string (blank to quit.):");
    fgets(main_string,SIZE,stdin);
    printf("Enter a sub string to find in main:");
    fgets(sub,SIZE,stdin);
    while(*main_string!='\n'){
        p=string_in(main_string,sub);
        printf("Done!\nNow the position of sub string is:");
        printf("%p\n",p);
        printf("Another? Enter a String as main string (blank to quit.):");
        fgets(main_string,SIZE,stdin);
        printf("Enter a sub string to find in main:");
        fgets(sub,SIZE,stdin);
    }

    return 0;
}

char *string_in(char *st,char *sub)
{
    int count=0;
    int src_len=strlen(sub);
    while(*st!='\0'&&count<src_len){
        if(*(st+count)==*(sub+count)){
            count++;
        }else{
            count=0;
            st++;
        }
    }
    if(count==src_len){
        return st;
    }else{
        return NULL;
    }
}