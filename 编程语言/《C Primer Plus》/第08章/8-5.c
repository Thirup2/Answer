#include <stdio.h>
#define MAX 100
#define MIN 0
int main(void)
{
    int guess_max=MAX;
    int guess_min=MIN;
    int guess;
    char ch;
    printf("准备好让我猜你的数了吗,按q退出,回车继续\n");
    while((ch=getchar())!='q'){
        if (ch=='\n')
        {
            break;
        }
    }
    if(ch=='q'){
        printf("再见\n");
    }else{
        guess=(MAX-MIN)/2;
        printf("你选的数是:%d吗?",guess);
        printf("(正确请输入\"t\",我猜的数偏大则输入\"b\",我猜的数偏小则输入\"l\")\n");
        while((ch=getchar())!='q'){
            if(ch=='t'){
                printf("我就知道是这个数,嘿嘿嘿!\n");
                break;
            }else if(ch=='b'){
                guess_max=guess;
                guess=guess_max-(guess_max-guess_min)/2;
                printf("那你选的数是:%d?\n",guess);
            }else if(ch=='l'){
                guess_min=guess;
                guess=guess_min+(guess_max-guess_min)/2;
                printf("那你选的数是:%d?\n",guess);
            }else if(ch=='q'){
                break;
            }else{
                printf("请输入选项字母\n");
            }
        }
        printf("再见!\n");
    }


    return 0;
}