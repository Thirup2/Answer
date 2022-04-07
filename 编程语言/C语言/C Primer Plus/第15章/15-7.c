#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define ID_MASK         0XFF
#define SIZE_MASK       0X7F00
#define ALIGN_MASK      0X18000
#define BOLD_MASK       0X20000
#define ITALIC_MASK     0X40000
#define UNDER_MASK      0X80000
unsigned int font_mode = 0;
const char align_mode[][8]={"left","center","right"};
const char on_off[][4]={"off","on"};
void show_menu(void);
void change_font(void);
void change_size(void);
void change_align(void);
void change_others(char ch);
int main(void)
{
    char selected;
    show_menu();
    scanf("%c",&selected);
    while(selected!='q'){
        while(getchar()!='\n'){
            continue;
        }
        switch(selected){
            case 'f':
                change_font();
                break;
            case 's':
                change_size();
                break;
            case 'a':
                change_align();
                break;
            default:
                change_others(selected);
                break;
        }
        show_menu();
        scanf("%c",&selected);
    }
    return 0;
}
void show_menu(void)
{
    int id=font_mode&ID_MASK;
    int size=(font_mode&SIZE_MASK)>>8;
    int align=(font_mode&ALIGN_MASK)>>15;
    int bold=(font_mode&BOLD_MASK)>>17;
    int italic=(font_mode&ITALIC_MASK)>>18;
    int underline=(font_mode&UNDER_MASK)>>19;
    printf("ID      SIZE    ALIGN   B       I       U\n");
    printf("%-8d%-8d%-8s%-8s%-8s%-8s\n",id,size,align_mode[align],on_off[bold],on_off[italic],on_off[underline]);
    printf("f)change font    s)change size    a)change alignment\n");
    printf("b)toggle bold    i)toggle italic  u)toggle underline\n");
    printf("q)quit\n");
}
void change_font(void)
{
    unsigned int n;
    printf("Enter font id (0-255):");
    scanf("%u",&n);
    while(getchar()!='\n'){
        continue;
    }
    font_mode&=~ID_MASK;
    font_mode|=n;
}
void change_size(void)
{
    unsigned int n;
    printf("Enter font size (0-127):");
    scanf("%u",&n);
    while(getchar()!='\n'){
        continue;
    }
    font_mode&=~SIZE_MASK;
    font_mode|=n<<8;
}
void change_align(void)
{
    char ch;
    printf("Select alignment:\nl)left     c)center     r)right\n");
    scanf("%c",&ch);
    while(getchar()!='\n'){
        continue;
    }
    font_mode&=(~ALIGN_MASK);
    if(ch=='l'){
        font_mode|=(0<<15);
    }
    if(ch=='c'){
        font_mode|=(1<<15);
    }
    if(ch=='r'){
        font_mode|=(2<<15);
    }
}
void change_others(char ch)
{
    int bold = (font_mode&BOLD_MASK)>>17;
    int italic = (font_mode&ITALIC_MASK)>>18;
    int underline = (font_mode&UNDER_MASK)>>19;
    if(ch=='b'){
        font_mode&=(~BOLD_MASK);
        font_mode|=~(bold<<17);
    }
    if(ch=='i'){
        font_mode&=(~ITALIC_MASK);
        font_mode|=~(italic<<18);
    }
    if(ch=='u'){
        font_mode&=(~UNDER_MASK);
        font_mode|=~(underline<<19);
    }
}