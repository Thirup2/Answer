#include <stdio.h>
#define SIZE 40
char *get_word(char *input);
int main(void)
{
    char input[SIZE];
    puts("请输入:");
    get_word(input);
    puts("您输入的第一个单词是:");
    puts(input);

    return 0;
}
char *get_word(char *input)
{
    char some[SIZE];
    char *in=some;
    fgets(some,SIZE,stdin);
    while((*in=='\n'||*in=='\t'||*in==' ')&&*in!='\0'){
        in++;
    }
    while(*in!='\n'&&*in!='\t'&&*in!=' '&&*in!='\0'){
        *input=*in;
        input++;
        in++;
    }

    return input;
}