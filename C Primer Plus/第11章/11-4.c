#include <stdio.h>
#define SIZE 40
char *get_word(char *input,int n);
int main(void)
{
    char input[SIZE];
    puts("请输入:");
    get_word(input,SIZE);
    puts("您输入的第一个单词是:");
    puts(input);

    return 0;
}
char *get_word(char *input,int n)
{
    char some[SIZE];
    char *in=some;
    fgets(some,SIZE,stdin);
    int i=0;
    while((*in=='\n'||*in=='\t'||*in==' ')&&*in!='\0'){
        in++;
    }
    while(*in!='\n'&&*in!='\t'&&*in!=' '&&*in!='\0'&&i<n){
        *input=*in;
        input++;
        in++;
        i++;
    }

    return input;
}