#include <stdio.h>
int main(int argc,char *argv[])
{
    if(argc<2){
        printf("Error! Not enough parameter to display!\n");
    }else{
        for(int i=argc;i>1;i--){
            printf("%s ",argv[i-1]);
        }
    }
    return 0;
}