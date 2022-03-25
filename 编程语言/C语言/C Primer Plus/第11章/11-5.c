#include <stdio.h>
#define SIZE 80
char *string_char(char *st,char c);
int main(void)
{
    char source[SIZE];
    char dest=' ';
    char *position;
    puts("请输入:");
    fgets(source,SIZE,stdin);
    while(dest!=EOF){
        puts("请输入你要查找的字符(EOF to quit):");
        while((dest=getchar())=='\n'){
            continue;
        }
        if((position=string_char(source,dest))!=NULL){
            printf("字符 %c 出现在地址:%p\n",*position,position);
        }else{
            printf("字符 %c 未被找到, 再试一遍?\n",dest);
        }
    }

    return 0;
}
char *string_char(char *st,char c)
{
    while(*st!='\0'){
        if(*st==c){
            return st;
        }else{
            st++;
        }
    }
    return NULL;
}