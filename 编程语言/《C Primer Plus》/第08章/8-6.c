#include <stdio.h>
char get_first(char);
int main(void)
{
    char ch;
    while((ch=getchar())!=EOF){
        printf("%c\n",get_first(ch));
    }

    return 0;
}
char get_first(char n){
    int a=n;
    while(getchar()!='\n'){
        continue;
    }
    return a;
}