#include <stdio.h>
int main(void)
{
    char ch;
    int i=0;
    while((ch=getchar())!='#'){
        if(ch=='\n'){
            printf("\\n=%-5d",'\n');
        }else{
            printf("%-2c=%-5d",ch,ch);
        }
        i++;
        if(i%8==0){
            printf("\n");
        }
    }

    return 0;
}