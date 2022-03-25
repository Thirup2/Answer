#include <stdio.h>
#define SIZE 10
#define NUM 40
void show_menu(void);
void source(char *input);
void ascii_source(char **input);
void lenthen(char **input);
void a_word(char **input);
int main(void)
{
    char input[SIZE][NUM];
    puts("请输入十个字符串:");
    for(int i=0;i<SIZE;i++){
        gets(input[i]);
    }//未实现读到EOF时停止
    show_menu();
    char ch;
    while((ch=getchar())!='q'){
        if(ch=='a'){
            for(int i=0;i<SIZE;i++){
                source(input[i]);
            }
        }else if(ch=='b'){
            ascii_source(input);
        }else if(ch=='c'){
            lenthen(input);
        }else if(ch=='d'){
            a_word(input);
        }else{
            printf("请输入正确的选项:\n");
        }
        while(getchar()!='\n'){
            continue;
        }
        show_menu();
    }
    puts("Bye!");

    return 0;
}
void show_menu(void)
{
    printf("*********************************************\n");
    printf("请输入选项:\n");
    printf("*********************************************\n");
    printf("a) 打印源字符串列表                         *\n");
    printf("b) 以ASCII中的顺序打印字符串                *\n");
    printf("c) 按长度递增顺序打印字符串                 *\n");
    printf("d) 按字符串中第1个单词的长度打印字符串      *\n");
    printf("q) 退出                                     *\n");
    printf("*********************************************\n");
}
void source(char *input)
{
    puts(input);
}
void ascii_source(char **input)
{
    
}
void lenthen(char **input)
{

}
void a_word(char **input)
{

}