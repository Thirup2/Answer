#include <stdio.h>
void pri(char,int,int);
int main(void)
{
    char ch;
    int col,row;
    printf("请输入你想要打印的字符:");
    scanf("%c",&ch);
    printf("请输入你每行想要打印的个数和总共的行数:");
    scanf("%d %d",&col,&row);
    pri(ch,col,row);
    

    return 0;
}
void pri(char ch,int col,int row)
{
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%c",ch);
        }
        printf("\n");
    }
}