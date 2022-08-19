#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE_SIZE 256
int main(int argc,char *argv[])
{
    char *line_one=(char *)malloc(LINE_SIZE * sizeof(char));
    char *line_two=(char *)malloc(LINE_SIZE * sizeof(char));

    int first_end=1;
    if(argc!=3){
        fprintf(stderr,"Usage:%s filename filename",argv[0]);
        exit(EXIT_FAILURE);
    }
    FILE *fp1,*fp2;
    if((fp1=fopen(argv[1],"r"))==NULL){
        fprintf(stderr,"Open %s failed\n",argv[1]);
        exit(EXIT_FAILURE);
    }
    if((fp2=fopen(argv[2],"r"))==NULL){
        fprintf(stderr,"Open %s failed\n",argv[2]);
        exit(EXIT_FAILURE);
    }
    printf("Print the line one by one.\n");
    int i=1;
    while(fgets(line_one,LINE_SIZE,fp1)!=NULL){
        if(fgets(line_two,LINE_SIZE,fp2)!=NULL){
            printf("File 1 LINE NO.%d : %s",i,line_one);
            printf("File 2 LINE NO.%d : %s",i,line_two);
            i++;
        }else{
            printf("File 1 LINE NO.%d : %s",i,line_one);
            i++;
        }
    }
    while(fgets(line_two,LINE_SIZE,fp2)!=NULL){
        printf("File 2 LINE NO.%d : %s",i++,line_two);
    }
    printf("\nPrint the combine line.\n");
    rewind(fp1);
    rewind(fp2);
    i=1;
    while(fgets(line_one,LINE_SIZE,fp1)!=NULL){
        if(fgets(line_two,LINE_SIZE,fp2)!=NULL){
            printf("LINE NO.%d :",i);
            while(*line_one!='\n'){
                putchar(*line_one++);
            }
            putchar('+');
            printf(" %s",line_two);
            i++;
        }else{
            printf("LINE NO.%d : %s",i,line_one);
            i++;
        }
    }
    while(fgets(line_two,LINE_SIZE,fp2)!=NULL){
        printf("LINE NO.%d : %s",i++,line_two);
    }
    fclose(fp1);
    fclose(fp2);

    return 0;
}