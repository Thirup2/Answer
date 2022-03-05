#include <stdio.h>
int let(char);
int main(void)
{
    char ch;
    while((ch=getchar())!=EOF){
        if(let(ch)>0){
            printf("%c是一个字母,在字母表中所处的数值位置是第%d位\n",ch,let(ch));
        }
        if(let(ch)==-1){
            printf("%c不是一个字母\n",ch);
        }
        while(getchar()!='\n'){
            continue;
        }
    }

    return 0;
}
int let(char ch)
{
    if(ch>='a'&&ch<='z'){
        return ch-'a'+1;
    }else if(ch>='A'&&ch<='Z'){
        return ch-'A'+1;
    }else{
        return -1;
    }
}