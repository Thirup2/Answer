#include <stdio.h>
int main(void)
{
    char ch;
    int i=1;
    while((ch=getchar())!=EOF){
        if(ch=='\n'){
            printf("\\n=%-5d",ch);
        }else{
            printf("%-2c=%-5d",ch,ch);
        }
        if(i%10==0){
            printf("\n");
        }
        i++;
    }

    return 0;
}