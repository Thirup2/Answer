#include <stdio.h>
int main(void)
{
    char ch;
    int counter_blank=0;
    int counter_n=0;
    int counter_other=0;
    while((ch=getchar())!='#'){
        if(ch==' '){
            counter_blank++;
        }else if(ch=='\n'){
            counter_n++;
        }else{
            counter_other++;
        }
    }
    printf("空格一共有:%d个\n换行符一共有:%d个\n其他字符一共有:%d个\n",counter_blank,counter_n,counter_other);

    return 0;
}