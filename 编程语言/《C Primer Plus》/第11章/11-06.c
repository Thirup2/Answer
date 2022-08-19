#include <stdio.h>
#define SIZE 80
int is_within(char c,char *st);
int main(void)
{
    char source[SIZE];
    char dest=' ';
    char *position;
    printf("请输入一条字符串:");
    fgets(source,SIZE,stdin);
    while(dest!=EOF){
        printf("请输入你要查找的字符:");
        while((dest=getchar())=='\n'){
            continue;
        }
        if(is_within(dest,source)!=0){
            printf("字符串中找到了 %c\n",dest);
        }else{
            printf("%c 无法在字符串中找到, 试试其他的?\n",dest);
        }
    }

    return 0;
}
int is_within(char c,char *st)
{
    while(*st!='\0'){
        if(*st==c){
            return 1;
        }else{
            st++;
        }
    }
    return 0;
}