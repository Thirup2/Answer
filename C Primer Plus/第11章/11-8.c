#include <stdio.h>
#include <string.h>
#define SIZE 40
char *string_in(char *s1,char *s2);
int main(void)
{
    char s1[SIZE];
    char s2[SIZE];
    char *ch;
    puts("请输入s1:");
    gets(s1);
    puts("请输入s2:");
    while(gets(s2)!=NULL&&s1!=NULL){
        if((ch=string_in(s1,s2))!=NULL){
            puts(ch);
        }else{
            puts("没有");
        }
        puts("请输入s1:");
        gets(s1);
        puts("请输入s2:");
    }

    return 0;
}
char *string_in(char *s1,char *s2)
{
    int i=0;int j=0;
    char *n;
    while(i<strlen(s1)&&j<strlen(s2)&&s2!=NULL&&s1!=NULL){
        if(s1[i]==s2[j]){
            n=s1+i-strlen(s2)+1;
            i++;
            j++;
        }else{
            i++;
            j=0;
            n=NULL;
        }
    }
    return n;
}
//问题一:考虑"this"和"hs"的例子,程序会返回"没有"
//问题二:函数中n赋值的位置