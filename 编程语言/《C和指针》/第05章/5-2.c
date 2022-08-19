#include <stdio.h>
int main(void)
{
    int ch;
    while((ch=getchar())!=EOF){
        if((ch>='a'&&ch<='m')||(ch>='A'&&ch<='M')){
            putchar(ch+13);
        }else if((ch>='n'&&ch<='z')||(ch>='N'&&ch<='Z')){
            putchar(ch-13);
        }else{
            putchar(ch);
        }
    }
    return 0;
}