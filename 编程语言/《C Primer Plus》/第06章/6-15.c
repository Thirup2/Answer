#include <stdio.h>
#include <string.h>
#define NUM 255
int main(void)
{
    char centence[255];
    printf("请输入一句话:\n");
    int i=0;
    while(scanf("%c",&centence[i])==1&&centence[i]!='\n'){
        i++;
    }
    for(int i=strlen(centence)-1;i>=0;i--){
        printf("%c",centence[i]);
    }

    return 0;
}