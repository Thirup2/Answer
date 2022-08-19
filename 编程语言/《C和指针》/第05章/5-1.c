#include <stdio.h>
int main(void)
{
    int ch;
    while((ch=getchar())!=EOF){
        if(ch>='A'&&ch<='Z'){
            putchar(ch-'A'+'a');
        }else{
            putchar(ch);
        }
    }
    return 0;
}