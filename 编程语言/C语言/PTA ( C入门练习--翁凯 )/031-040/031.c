#include <stdio.h>
void getbit(int num,int *n,int row);
int main(void)
{
    int ncur,npre;
    int n[5];
    scanf("%d",&ncur);
    npre=-1;
    for(int i=1;ncur!=npre;i++){
        npre=ncur;
        getbit(ncur,n,5);
        ncur=(n[0]+n[1]+n[2]+n[3]+n[4])*3+1;
        printf("%d:%d\n",i,ncur);
    }

    return 0;
}
void getbit(int num,int *n,int row)
{
    n[4]=num%10;
    num=num/10;
    n[3]=num%10;
    num=num/10;
    n[2]=num%10;
    num=num/10;
    n[1]=num%10;
    num=num/10;
    n[0]=num;
}