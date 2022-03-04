#include <stdio.h>
void showmenu(void);
float get_num1(void);
float get_num2(char);
int main(void)
{
    char ch;
    float num1,num2;
    while(1)
    {
        showmenu();
        while((ch=getchar())!='a'&&ch!='s'&&ch!='m'&&ch!='d'&&ch!='q'){
            printf("请输入正确的选项字母\n");
            while(getchar()!='\n'){
                continue;
            }
        }
        if(ch=='q'){
            break;
        }
        num1=get_num1();
        num2=get_num2(ch);
        if(ch=='a'){
            printf("%g + %g = %g\n",num1,num2,num1+num2);
        }else if(ch=='s'){
            printf("%g - %g = %g\n",num1,num2,num1-num2);
        }else if(ch=='m'){
            printf("%g * %g = %g\n",num1,num2,num1*num2);
        }else if(ch=='d'){
            printf("%g / %g = %g\n",num1,num2,num1/num2);
        }
    }
    printf("Bye.\n");

    return 0;
}
void showmenu(void)
{
    printf("Enter the operation of your choice:\n");
    printf("a. add               s. subtract\n");
    printf("m. multiply          d. divide\n");
    printf("q. quit\n");
}
float get_num1(void)
{
    float n;
    char ch;
    printf("Enter first number:");
    while(1){
        if(scanf("%f",&n)==1){
            while(getchar()!='\n'){
                continue;
            }
            return n;
        }else{
            while((ch=getchar())!='\n'){
                putchar(ch);
            }
            printf(" is not a number.\n");
            printf("please enter a number, such as 2.5, -1.78E8, or 3:");
        }
    }
}
float get_num2(char m)
{
    float n;
    char ch;
    printf("Enter second number:");
    if(m!='d'){
        while(1){
            if(scanf("%f",&n)==1){
                while(getchar()!='\n'){
                    continue;
                }
                return n;
            }else{
                while((ch=getchar())!='\n'){
                    putchar(ch);
                }
                printf(" is not a number.\n");
                printf("please enter a number, such as 2.5, -1.78E8, or 3:");
            }
        }
    }else{
        while(1){
            n=0;
            if(scanf("%f",&n)==1&&n==0){
                printf("Enter a number other than 0:");
            }else if(n!=0){
                while(getchar()!='\n'){
                    continue;
                }
                return n;
            }else{
                while((ch=getchar())!='\n'){
                    putchar(ch);
                }
                printf(" is not a number.\n");
                printf("please enter a number, such as 2.5, -1.78E8, or 3:");
            }
        }
    }
}