#include <stdio.h>
int main(void)
{
    char ch;
    int count=0;
    while((ch=getchar())!='#'){
        if(ch=='.'){
            printf("!");
            count++;
        }else if(ch=='!'){
            printf("!!");
            count++;
        }else{
            printf("%c",ch);
        }
    }
    printf("一共进行了%d次替换\n",count);

    return 0;
}