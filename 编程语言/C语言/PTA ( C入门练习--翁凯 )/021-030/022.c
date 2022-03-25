#include <stdio.h>
int main(void)
{
    int a,b,c;
    char an;
    scanf("%d %d %d",&a,&b,&c);
    if(a==b){
        an='C';
    }
    if(a==c){
        an='B';
    }
    if(b==c){
        an='A';
    }
    printf("%c",an);

    return 0;
}