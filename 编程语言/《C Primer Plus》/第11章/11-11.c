#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 80
#define NUM 5
void show_menu(void);
void input_string(int number,char st[][SIZE]);
void print_original(int number,char st[][SIZE]);
void print_ascii(int number,char st[][SIZE]);
void print_length(int number,char st[][SIZE]);
void print_words(int number,char st[][SIZE]);
void sort_order(int number,int order[][2]);
int get_word_length(char *input);
int main(void)
{
    char test[NUM][SIZE];
    char ch;
    input_string(NUM,test);
    show_menu();
    scanf("%c",&ch);
    while(ch!='q'){
        switch (ch){
            case 'a':
                print_original(NUM,test);
                break;
            case 'b':
                print_ascii(NUM,test);
                break;
            case 'c':
                print_length(NUM,test);
                break;
            case 'd':
                print_words(NUM,test);
                break;
            default:
                printf("请输入正确的选项\n");
                break;
        }
        while(getchar()!='\n'){
            continue;
        }
        show_menu();
        scanf("%c",&ch);
    }
    printf("Bye!");

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
void input_string(int number,char st[][SIZE]){
    printf("请输入%d个字符串:\n",number);
    for(int i=0;i<number;i++){
        fgets(st[i],SIZE,stdin);
    }
}
void print_original(int number,char st[][SIZE])
{
    printf("打印源字符串列表.\n");
    for(int i=0;i<number;i++){
        printf("%d. %s",i,st[i]);
    }
}
void print_ascii(int number,char st[][SIZE])
{
    printf("以ASCII中的顺序打印字符串.\n");
    int order[number][2];
    for(int i=0;i<number;i++){
        order[i][0]=i;
        order[i][1]=st[i][0];
    }
    sort_order(number,order);
    for(int i=0;i<number;i++){
        printf("ASCII No.%d. %s",i,st[order[i][0]]);
    }
}
void print_length(int number,char st[][SIZE])
{
    printf("按长度递增顺序打印字符串.\n");
    int order[number][2];
    for(int i=0;i<number;i++){
        order[i][0]=i;
        order[i][1]=strlen(st[i]);
    }
    sort_order(number,order);
    for(int i=0;i<number;i++){
        printf("LENGTH No.%d. %s",i,st[order[i][0]]);
    }
}
void print_words(int number,char st[][SIZE])
{
    printf("按字符串中第1个单词的长度打印字符串.\n");
    int order[number][2];
    for(int i=0;i<number;i++){
        order[i][0]=i;
        order[i][1]=get_word_length(st[i]);
    }
    sort_order(number,order);
    for(int i=0;i<number;i++){
        printf("WORDS No.%d. %s",i,st[order[i][0]]);
    }
}
void sort_order(int number,int order[][2])
{
    int temp[2];
    for(int i=0;i<number-1;i++){
        for(int j=0;j<number-1-i;j++){
            if(order[j][1]>order[j+1][1]){
                temp[0]=order[j][0];
                temp[1]=order[j][1];
                order[j][0]=order[j+1][0];
                order[j][1]=order[j+1][1];
                order[j+1][0]=temp[0];
                order[j+1][1]=temp[1];
            }
        }
    }
}
int get_word_length(char *input)
{
    char *in=input;
    int length=0;
    while(isalpha(*in)==0){
        in++;
    }
    while(isalpha(*in)!=0){
        in++;
        length++;
    }
    return length;
}