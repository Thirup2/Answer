#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"

char menu(void);
void addpet(Tree * pt);
void droppet(Tree * pt);
void showpets(const Tree * pt);
void findpet(const Tree * pt);
void printitem(Item item);
void uppercase(char * str);
char * s_gets(char *st,int n);
int main(void)
{
    Tree pets;
    char choice;

    InitializeTree(&pets);
    while((choice=menu())!='q'){
        switch(choice){
            case 'a':
                addpet(&pets);
                break;
            case 'l':
                showpets(&pets);
                break;
            case 'f':
                findpet(&pets);
                break;
            case 'n':
                printf("%d pets in club\n",TreeItemCount(&pets));
                break;
            case 'd':
                droppet(&pets);
                break;
            default:
                puts("Switching error");
        }
    }
    DeleteAll(&pets);
    puts("Bye.");

    return 0;
}

char menu(void)
{
    int ch;

    puts("Nerfville pet Club Membership Program");
    puts("Enter the letter corresponding to your choice: ");
    puts("a)add a pet       l)show list of pets");
    puts("n)number of pets  f)find pets");
    puts("d)delete a pet    q)quit");
    while((ch=getchar())!=EOF){
        while(getchar()!='\n'){
            continue;
        }
        ch=tolower(ch);
        if(strchr("alrfndq",ch)==NULL){
            puts("Please enter an a, l, f, n, d, or q: ");
        }else{
            break;
        }
    }
    if(ch==EOF){
        ch='q';
    }
    return ch;
}

void addpet(Tree *pt)
{
    Item temp;

    if(TreeIsFull(pt)){
        puts("No room in the club!");
    }else{
        puts("Please enter name of pet: ");
        s_gets(temp.petname,SLEN);
        puts("Please enter pet kind: ");
        s_gets(temp.petkind[0],SLEN);
        uppercase(temp.petname);
        uppercase(temp.petkind[0]);
        AddItem(&temp,pt);
    }
}

void showpets(const Tree *pt)
{
    if(TreeIsEmpty(pt)){
        puts("No enteries!");
    }else{
        Traverse(pt,printitem);
    }
}

void printitem(Item item)
{
    int i=0;
    while(strlen(item.petkind[i])>0){
        printf("pet: %-19s kind: %-19s\n",item.petname,item.petkind[i]);
        i++;
    }
}

void findpet(const Tree * pt)
{
    Item temp;
    if(TreeIsEmpty(pt)){
        puts("No entries!");
        return;
    }
    puts("Please enter name of pet you wish to find: ");
    s_gets(temp.petname,SLEN);
    puts("Please enter pet kind: ");
    s_gets(temp.petkind[0],SLEN);
    uppercase(temp.petname);
    uppercase(temp.petkind[0]);
    printf("%s the %s ",temp.petkind[0],temp.petname);
    if(InTree(&temp,pt)){
        printf("is a member.\n");
    }else{
        printf("is not a member .\n");
    }
}

void droppet(Tree * pt){
    Item temp;

    if(TreeIsEmpty(pt)){
        puts("No entries!");
        return;
    }
    puts("Please enter name of pet you wish to delete: ");
    s_gets(temp.petname,SLEN);
    puts("Please enter pet kind: ");
    s_gets(temp.petkind[0],SLEN);
    uppercase(temp.petname);
    uppercase(temp.petkind[0]);
    printf("%s the %s ", temp.petname,temp.petkind[0]);

    if(DeleteItem(&temp,pt)){
        printf("is dropped from the club.\n");
    }else{
        printf("is not a member.\n");
    }
}

void uppercase(char * str){
    while(*str){
        *str=toupper(*str);
        str++;
    }
}

char *s_gets(char *st,int n)
{
    char *ret_val;
    char *find;
    ret_val=fgets(st,n,stdin);
    if(ret_val){
        find=strchr(st,'\n');
    }
    if(find){
        *find='\0';
    }else{
        while(getchar()!='\n'){
            continue;
        }
    }
    return ret_val;
}