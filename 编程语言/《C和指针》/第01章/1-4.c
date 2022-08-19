#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 1000
int main(void)
{
    int i;
    char ch[MAXSIZE];
    char ch_max[MAXSIZE];
    char n;
    int max_num;
    i=0;
    max_num=0;
    while((n=getchar())!=EOF){
        do{
            ch[i]=n;
            i++;
        }while((n=getchar())!=EOF&&n!='\n');
        if(i>max_num){
            max_num=i;
            for(int j=0;j<i;j++){
                ch_max[j]=ch[j];
            }
            ch_max[i]='\0';
        }
        i=0;
    }
    printf("%s\n",ch_max);

    return EXIT_SUCCESS;
}