#include <stdio.h>
void chline(char,int,int);
int main(void)
{
    int i,j;
    char ch;
    printf("请输入你想打印的字符:");
    scanf("%c",&ch);
    printf("请输入你想打印的行列数:");
    scanf("%d %d",&i,&j);
    chline(ch,i,j);

    return 0;
}
void chline(char ch,int i,int j)
{
    for(int m=0;m<i;m++){
        for(int n=0;n<j;n++){
            printf("%c",ch);
        }
        printf("\n");
    }
}