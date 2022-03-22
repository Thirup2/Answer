#include <stdio.h>
#define SIZE 40
char *delete_space(char *input);
int main(void)
{
    char input[SIZE];
    puts("请输入:");
    while(gets(input)!=NULL){
        puts(delete_space(input));
    }

    return 0;
}
char *delete_space(char *input)
{
    char *some=NULL;
    int i=0;
    int j=0;
    while(input[i]!='\0'){
        if(input[i]==' '){
            i++;
        }else{
            *(some+j)=*(input+i);
            i++;
            j++;
        }
    }
    *(some+j)='\0';

    return some;
}
//问题一:循环条件
//问题二:异常终止