#include <stdio.h>
#include <string.h>
char * s_gets(char * st, int n);
#define MAXTITL   40
#define MAXAUTL   40
#define MAXBKS   100
struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};
void orig_output(struct book library[],int row);
void nameup_out(struct book library[],int row);
void priceup_out(struct book library[],int row);

int main(void)
{
    struct book library[MAXBKS];
    int count = 0;
    int index;
    
    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
           && library[count].title[0] != '\0')
    {
        printf("Now enter the author.\n");
        s_gets(library[count].author, MAXAUTL);
        printf("Now enter the value.\n");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n')
            continue;
        if (count < MAXBKS)
            printf("Enter the next title.\n");
    }
    
    if (count > 0)
    {
        printf("按照原顺序输出:\n");
        orig_output(library,count);
        printf("按照书名字母顺序输出:\n");
        nameup_out(library,count);
        printf("按照价格升序输出:\n");
        priceup_out(library,count);
    }
    else
    	printf("No books? Too bad.\n");
    
    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;
    
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}
void orig_output(struct book library[],int row)
{
    for(int i=0;i<row;i++){
        printf("%s--%s saled %.2f RMB\n",library[i].title,library[i].author,library[i].value);
    }
}
void nameup_out(struct book library[],int row)
{
    char *ptitle[row];
    char *temp;
    int top,seek;
    for(int i=0;i<row;i++){
        ptitle[i]=library[i].title;
    }
    for(top=0;top<row-1;top++){
        for(seek=top+1;seek<row;seek++){
            if(strcmp(ptitle[top],ptitle[seek])>0){
                temp=ptitle[top];
                ptitle[top]=ptitle[seek];
                ptitle[seek]=temp;
            }
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<row;j++){
            if(ptitle[i]==library[j].title){
                printf("%s--%s saled %.2f RMB\n",library[j].title,library[j].author,library[j].value);
            }
        }
    }
}
void priceup_out(struct book library[],int row)
{
    float *pvalue[row];
    float *temp;
    int top,seek;
    for(int i=0;i<row;i++){
        pvalue[i]=&library[i].value;
    }
    for(top=0;top<row-1;top++){
        for(seek=top+1;seek<row;seek++){
            if(*pvalue[top]>*pvalue[seek]){
                temp=pvalue[top];
                pvalue[top]=pvalue[seek];
                pvalue[seek]=temp;
            }
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<row;j++){
            if(*pvalue[i]==library[j].value){
                printf("%s--%s saled %.2f RMB\n",library[j].title,library[j].author,library[j].value);
            }
        }
    }
}