#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define row 20
#define col 30
int main(int argc,char *argv[])
{
    FILE *fin,*fout;
    int data[row][col];
    char file_input[]="target.txt";
    char file_output[]="file.txt";

    char convert[]={' ','.','\'',':','~','*','=','$','%','#'};
    if((fin=fopen(file_input,"r"))==NULL){
        printf("Can not open file %s.\n",file_input);
        exit(EXIT_FAILURE);
    }
    if((fout=fopen(file_output,"w"))==NULL){
        printf("Can not open file %s.\n",file_output);
        exit(EXIT_FAILURE);
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            fscanf(fin,"%d",&data[i][j]);
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%c",convert[data[i][j]]);
            fprintf(fout,"%c",convert[data[i][j]]);
        }
        printf("\n");
        fprintf(fout,"\n");
    }
    fclose(fin);
    fclose(fout);

    return 0;
}