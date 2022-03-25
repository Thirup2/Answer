#include <stdio.h>
int main(void)
{
    int result=0;
    int make;
    char ch;
    scanf("%d",&result);
    ch=getchar();
    do{
        scanf("%d",&make);
        switch (ch)
        {
            case '+':
                result+=make;
                break;
            case '-':
                result-=make;
                break;
            case '*':
                result*=make;
                break;
            case '/':
                if(make==0){
                    printf("ERROR");
                    return 0;
                }else{
                    result/=make;
                }
                break;
            case '=':
                printf("%d",result);
                return 0;
            default:
                printf("ERROR");
                return 0;
        }
    }
    while((ch=getchar())!='=');
    printf("%d",result);

    return 0;
}