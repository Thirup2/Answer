#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 256
int string_in(char * st,char * sub);
int main(int argc,char *argv[])
{
    FILE *fp;
    char buffer[SIZE];
    char *seek_string;
    if(argc<3){
        printf("Usage:%s string file_name ...\n",argv[0]);
        exit(EXIT_FAILURE);
    }
    seek_string=argv[1];

    if((fp=fopen(argv[2],"r"))==NULL){
        printf("Can not open the file %s \n",argv[2]);
        exit(EXIT_FAILURE);
    }
    while(fgets(buffer,SIZE,fp)!=NULL){
        if(string_in(buffer,seek_string)){
            puts(buffer);
        }
    }
    return 0;
}
int string_in(char *st,char *sub)
{
    int count=0;
    int src_len=strlen(sub);
    while(*st!='\0'&&count<src_len){
        if(*(st+count)==*(sub+count)){
            count++;
        }else{
            count=0;
            st++;
        }
    }
    if(count==src_len){
        return 1;
    }else{
        return 0;
    }
}