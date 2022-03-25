#include <stdio.h>
#define LENTH 40
char *read_char(char *input,int n);
int main(void)
{
    char input[LENTH];
    puts("请输入:");
    read_char(input,LENTH);
    puts("你的输入是:");
    puts(input);

    return 0;
}
char *read_char(char *input,int n)
{
    int i=0;
    do{
        input[i]=getchar();
        if(input[i]==' '||input[i]=='\n'||input[i]=='\t'){
            break;
        }
    }while(input[i]!=EOF&&++i<n);

    return input;
}