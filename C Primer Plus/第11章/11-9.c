#include <stdio.h>
#include <string.h>
#define SIZE 40
void remo(char *input,int n);
int main(void)
{
    char input[SIZE];
    puts("请输入:");
    while(gets(input)!=NULL){
        remo(input,strlen(input));
        puts(input);
        puts("请输入:");
    }

    return 0;
}
void remo(char *input,int n)
{
    char some;
    for(int i=0;i<n/2;i++){
        some=input[i];
        input[i]=input[n-i-1];
        input[n-i-1]=some;
    }
}