#include <stdio.h>
int main(void)
{
    char ch;
    int count=0;
    while((ch=getchar())!='#'){
        switch (ch)
        {
        case '.':
            printf("!");
            count++;
            break;
        case '!':
            printf("!!");
            count++;
            break;
        default:
            printf("%c",ch);
            break;
        }
    }
    printf("一共进行了%d次替换\n",count);

    return 0;
}