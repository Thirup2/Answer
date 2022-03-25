#include <stdio.h>
#include <string.h>
#define SIZE 80

char* mystrncpy(char * dest, char *src,int n);
int main(void)
{
    char destination[SIZE],source[SIZE];
    int i=0;
    printf("Enter a String as s source (blank to quit.):");
    fgets(source,SIZE,stdin);
    printf("Enter number of char you need to copy:");
    scanf("%d",&i);
    while(*source!='\n'){
        mystrncpy(destination,source,i);
        printf("Done!\nNow the dest string is:");
        puts(destination);
        while(getchar()!='\n'){
            break;
        }
        printf("Another? Enter a String as s source(blank to quit.):");
        fgets(source,SIZE,stdin);
        printf("Enter number of char you need to copy:");
        scanf("%d",&i);
    }
    
    return 0;
}

char *mystrncpy(char *dest,char *src,int n)
{
    int count=0;
    while(*src!='\0'&&count<n){
        *(dest+count++)=*src++;
    }
    if(count<n){
        while(count<n){
            *(dest+count++)='\0';
        }
    }
    return dest;
}
