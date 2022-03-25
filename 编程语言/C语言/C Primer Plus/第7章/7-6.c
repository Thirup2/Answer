#include <stdio.h>
int main(void)
{
    char f_ch;
    char l_ch;
    int count=0;
    while((f_ch=getchar())!='#'){
        if(l_ch=='e'&&f_ch=='i'){
            count++;
        }else{
            l_ch=f_ch;
        }
    }
    printf("一共出现了%d次\"ei\"",count);

    return 0;
}