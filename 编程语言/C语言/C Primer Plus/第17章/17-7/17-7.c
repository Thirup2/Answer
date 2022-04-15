#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "tree.h"

char show_menu(void);
void show_item(Item item);
extern void find_word(const Tree * pt);
int main(int argc,char * argv[])
{
    char choice;
    Tree word_tree;
    FILE * fp;
    Item temp;

    if(argc!=2){
        fprintf(stderr,"Usage:commond filename\n");
        exit(1);
    }
    if((fp=fopen(argv[1],"r"))==NULL){
        fprintf(stderr,"Can't open %s\n",argv[1]);
        exit(2);
    }

    InitializeTree(&word_tree);

    while(fscanf(fp,"%s",temp.word)==1){
        if(!isalpha(temp.word[0])){
            continue;
        }
        if(!isalpha(temp.word[strlen(temp.word)-1])){
            temp.word[strlen(temp.word)-1]='\0';
        }
        temp.times=1;
        AddItem(&temp,&word_tree);
    }

    fclose(fp);
    printf("file is opened, what do you want to do:\n");
    while((choice=show_menu())!='q'){
        switch (choice){
            case 's':
                Traverse(&word_tree,show_item);
                break;
            case 'r':
                find_word(&word_tree);
                break;
            case 'q':
                break;
            default:
                puts("Switching error");
                break;
        }
    }
    puts("Bye!");
    DeleteAll(&word_tree);
    return 0;
}
char show_menu(void)
{
    int ch;
    printf("s)show all words and its times\n");
    printf("r)find a word and report its times\n");
    printf("q)quit\n");
    while((ch=getchar())!=EOF){
        while(getchar()!='\n'){
            continue;
        }
        ch=tolower(ch);
        if(strchr("srq",ch)==NULL){
            puts("Please enter an s , r or q: ");
        }else{
            break;
        }
    }
    if(ch==EOF){
        ch='q';
    }
    return ch;
}
void show_item(Item item)
{
    printf("%s appear %d times\n",item.word,item.times);
}