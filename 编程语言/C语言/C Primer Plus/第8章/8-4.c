#include <stdio.h>
#include <stdbool.h>
int main(void)
{
    char ch;
    int word=0;
    int letter=0;
    bool i=false;

    while((ch=getchar())!=EOF){
        if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')){
            letter++;
            i=true;
        }else if(i){
            word++;
            i=false;
        }
    }
    printf("一共有%d个单词,一共有%d个字母\n所以每个单词平均%lf个字母\n",word,letter,1.0*letter/word);
    
    return 0;
}