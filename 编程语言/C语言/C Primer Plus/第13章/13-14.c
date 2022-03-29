#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void read_data(int row,int col,int data[row][col],FILE *fp);
void write_data(int row,int col,int data[row][col],FILE *fp);
int data_diffusion(int row,int col,int data[row][col],int x,int y);
static const char convert[]={' ','.','\'',':','~','*','=','$','%','#'};
int main(int argc,char *argv[])
{
    FILE *fin,*fout;
    int row=20;
    int col=30;
    int data_matrix[row][col];
    char file_input[]="target.txt";
    char file_output[]="file.txt";

    if((fin=fopen(file_input,"r"))==NULL){
        printf("Can not open file %s.\n",file_input);
        exit(EXIT_FAILURE);
    }
    if((fout=fopen(file_output,"w"))==NULL){
        printf("Can not open file %s.\n",file_output);
        exit(EXIT_FAILURE);
    }
    read_data(row,col,data_matrix,fin);
    for(int i=0;i<row;i++){
        for(int j;j<col;j++){
            data_matrix[i][j]=data_diffusion(row,col,data_matrix,i,j);
        }
    }
    write_data(row,col,data_matrix,fout);
    fclose(fin);
    fclose(fout);

    return 0;
}
void read_data(int row,int col,int data[row][col],FILE *fin)
{
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            data[i][j]=getc(fp)-48;
        }
        getc(fp);
    }
}
void write_data(int row,int col,int data[row][col],FILE *fp)
{
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%c",convert[data[i][j]]);
            fprintf(fp,"%c",convert[data[i][j]]);
        }
        putchar('\n');
        putc('\n',fp);
    }
}
int data_diffusion(int row,int col,int data[row][col],int x,int y)
{
    int average;
    if(x==0){
        if(y==0){
            if(abs(data[x][y]-data[x][y+1])>1&&abs(data[x][y]-data[x+1][y])>1&&
            abs(data[x][y]-data[x+1][y+1])>1){
                return (data[x][y]+data[x][y+1]+data[x+1][y]+data[x+1][y+1])/4;
            }
        }
        if(y==col-1){
            if(abs(data[x][y]-data[x][y-1])>1&&abs(data[x][y]-data[x+1][y])>1&&
            abs(data[x][y]-data[x+1][y-1])>1){
                return (data[x][y]+data[x][y-1]+data[x+1][y]+data[x+1][y-1])/4;
            }
        }
        if(abs(data[x][y]-data[x][y-1])>1&&abs(data[x][y]-data[x+1][y])>1&&
        abs(data[x][y]-data[x+1][y-1])>1&&abs(data[x][y]-data[x][y+1])>1&&
        abs(data[x][y]-data[x+1][y+1])>1){
            return (data[x][y]+data[x][y-1]+data[x][y+1]+data[x+1][y-1]+data[x+1][y]+data[x+1][y+1])/6;
        }
    }else if(x==row-1){
        if(y==0){
            if(abs(data[x][y]-data[x-1][y])>1&&abs(data[x][y]-data[x][y+1])>1&&
            abs(data[x][y]-data[x-1][y+1])>1){
            return (data[x][y]+data[x-1][y]+data[x][y+1]+data[x-1][y+1])/4;
            }
        }
        if(y==col-1){
            if(abs(data[x][y]-data[x][y-1])>1&&abs(data[x][y]-data[x-1][y])>1&&
            abs(data[x][y]-data[x-1][y-1])>1){
                return (data[x][y]+data[x][y-1]+data[x-1][y]+data[x-1][y-1])/4;
            }
        }
        if(abs(data[x][y]-data[x-1][y])>1&&abs(data[x][y]-data[x][y+1])>1&&
        abs(data[x][y]-data[x-1][y+1])>1&&abs(data[x][y]-data[x][y-1])>1&&
        abs(data[x][y]-data[x-1][y-1])>1){
                return (data[x][y]+data[x][y-1]+data[x-1][y]+data[x-1][y-1]+data[x][y+1]+data[x-1][y+1])/6;
        }
    }
    if(y==0){
        if(abs(data[x][y]-data[x-1][y])>1&&abs(data[x][y]-data[x-1][y+1])>1&&
        abs(data[x][y]-data[x][y+1])>1&&abs(data[x][y]-data[x+1][y])>1&&
        abs(data[x][y]-data[x+1][y+1])>1){
                return (data[x][y]+data[x-1][y]+data[x-1][y+1]+data[x][y+1]+data[x+1][y]+data[x+1][y+1])/6;
            }
    }else if(y==col-1){
        if(abs(data[x][y]-data[x-1][y])>1&&abs(data[x][y]-data[x-1][y-1])>1&&
        abs(data[x][y]-data[x][y-1])>1&&abs(data[x][y]-data[x+1][y])>1&&
        abs(data[x][y]-data[x+1][y+1])>1){
                return (data[x][y]+data[x-1][y]+data[x-1][y-1]+data[x][y-1]+data[x+1][y]+data[x+1][y+1])/6;
            }
    }
    if(abs(data[x][y]-data[x-1][y-1])>1&&abs(data[x][y]-data[x-1][y])>1&&
    abs(data[x][y]-data[x-1][y+1])>1&&abs(data[x][y]-data[x][y-1])>1&&
    abs(data[x][y]-data[x][y+1])>1&&abs(data[x][y]-data[x+1][y-1])>1&&
    abs(data[x][y]-data[x+1][y])>1&&abs(data[x][y]-data[x+1][y+1])>1){
        return (data[x][y]+data[x-1][y-1]+data[x-1][y]+data[x-1][y+1]+
        data[x][y-1]+data[x][y+1]+data[x+1][y-1]+data[x+1][y]+data[x+1][y+1])/9;
    }
    return data[x][y];
}