#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    int amount;
    printf("How many words do you wish to enter? ");
    scanf("%d",&amount);
    printf("Enter %d words now: \n",amount);
    char **pst=(char **)malloc(amount * sizeof(char *));
    for(int i=0;i<amount;i++){
        char temp[100];
        scanf("%s",temp);
        int length=strlen(temp);
        char *str=(char *)malloc(length*sizeof(char));
        strcpy(str,temp);
        *(pst+i)=str;
    }
    printf("Here are your word:\n");
    for(int i=0;i<amount;i++){
        printf("%s\n",*(pst+i));
    }
    free(pst);

    return 0;
}