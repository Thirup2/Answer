#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct secuer {
    char num[30];
    struct {
        char last_name[15];
        char mid_name[15];
        char first_name[15];
    };
};
struct secuer some[5]={
        {"302039823",{"Dribble","Mike","Flossie"}}
    };
void print_a(struct secuer name[],int row);
void print_b(struct secuer name);
int main(void)
{
    printf("Test to printf struct contents:\n");
    print_a(some,5);
    print_b(some[0]);   //可用交互输入与循环计数，然后根据计数循环录入

    return 0;
}
void print_a(struct secuer name[],int row)
{
    printf("第一种打印：\n");
    for(int i=0;i<row;i++){
        if(strlen(name[i].num)<9){
            break;
        }
        printf("No.%d: %s, ",i+1,name[i].last_name);
        printf("%s ",name[i].first_name);
        if(strlen(name[i].mid_name)>0){
            printf("%c. ",name[i].mid_name[0]);
        }
        printf("-- %s",name[i].num);
        printf("\n");
    }
}
void print_b(struct secuer name)
{
    printf("第二种打印：\n");
    if(strlen(name.num)<9){
        return;
    }
    printf("USERID: %s, ",name.last_name);
    printf("%s ",name.first_name);
    if(strlen(name.mid_name)>0){
        printf("%c. ",name.mid_name[0]);
    }
    printf("-- %s",name.num);
    printf("\n");

    return;
}