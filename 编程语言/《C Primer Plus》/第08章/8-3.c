#include <stdio.h>
int main(void)
{
    char ch;
    int counta=0;int countA=0;
    while((ch=getchar())!=EOF){
        if(ch>='a'&&ch<='z'){
            counta++;
        }
        if(ch>='A'&&ch<='Z'){
            countA++;
        }
    }
    printf("大写字母个数:%d\n小写字母个数:%d\n",countA,counta);

    return 0;
}