#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40

int main(int argc, char *argv[])
{
    FILE  *in, *out;
    int ch;
    char name[LEN];
    char file1[LEN];
    int count = 0;
    printf("请输入写入文件：");
    scanf("%s",file1);
    if ((in = fopen(file1, "r")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file \"%s\"\n",
                file1);
        exit(EXIT_FAILURE);
    }
    strncpy(name,file1, LEN - 5);
    name[LEN - 5] = '\0';
    strcat(name,".red");
    if ((out = fopen(name, "w")) == NULL)
    {
        fprintf(stderr,"Can't create output file.\n");
        exit(3);
    }
    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out);
    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr,"Error in closing files\n");
    
    return 0;
}